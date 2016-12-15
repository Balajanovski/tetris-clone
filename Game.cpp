//
// Created by JULIA BALAJAN on 3/12/2016.
//
#include <random>
#include <ncurses.h>
#include "Game.h"

int Game::get_next_block() {
    int val;
    while (true) {
        std::random_device generator;
        std::uniform_int_distribution<int> distribution(0,4);

        if((val = distribution(generator)) != prev_block)
            return val;
    }
}

// Stores template for all the different tetris pieces
cCoord Game::struct_coords[][MAX_COORDINATES + 1] = {{
                                                  /* Row: 1 */ {0, 0}, {1, 0}, {2, 0},
                                                  /* Row: 2 */ {0, 1},
                                          },
                                          {
                                                  /* Row: 1 */ {0, 0}, {1, 0},
                                                  /* Row: 2 */ {0, 1}, {1, 1},
                                          },
                                          {
                                                  /* Row: 1 */ {0, 0},
                                                  /* Row: 2 */ {0, 1},
                                                  /* Row: 3 */ {0, 2},
                                                  /* Row: 4 */ {0, 3},
                                          },
                                          {
                                                  /* Row: 1 */         {1, 0}, {2, 0},
                                                  /* Row: 2 */ {0, 1}, {1, 1},
                                          },
                                          {
                                                  /* Row: 1 */         {1, 0},
                                                  /* Row: 2 */ {0, 1}, {1, 1}, {2, 1},
                                          }};

// Stores the origins coords for all the different tetris pieces
cCoord Game::struct_origins[MAX_COORDINATES + 1] = {
        /* L Shaped */      {0, 0},
        /* Square shaped */ {0, 0},
        /* Stick shaped */  {0, 0},
        /* Stair shaped */  {1, 0},
        /* T shaped */      {1, 1},
};

Game::Game() {
    create_block();
}



inline void Game::create_block() {
    s.push_back(Structure(get_next_block()));
}

inline Structure& Game::get_last_block() {
    return *(s.end() - 1);
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::matrix_init() {
    int x,
        y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            bool foundBlockFlag = false;

            for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y()) {
                        printw("█");
                        foundBlockFlag = true;
                        break;
                    }

            if (!foundBlockFlag) {
                move(y, x);
                printw(" ");
            }
        }
        move(y, x);
        printw("\n");
    }
}

void Game::draw () {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            bool foundBlockFlag = false;
            for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y() && static_cast<char>(mvinch(y, x)) != blockChar) {
                        move(y, x);
                        printw("█");
                        foundBlockFlag = true;
                        break;
                    }

            if (!foundBlockFlag) {
                move(y, x);
                printw(" ");
            }
        }
    }
}

void Game::controls () {
    switch(getch()) {
        case 'q' : case 'Q' :
            get_last_block().rotate_left();
            break;
        case 'e' : case 'E' :
            get_last_block().rotate_right();
            break;
        case 'a' : case 'A' :
            get_last_block().move_left();
            break;
        case 'd' : case 'D' :
            get_last_block().move_right();
            break;
        case 'x' : case 'X' :
            gameOver = true;
            break;
        case 's' : case 'S' :
            setSpeed(100);
            break;
    }
}

void Game::destroy() {
    int counter = 0;
    for (int y = height-1; y >= 1; --y) {
        for (int x = 0; x < width; ++x) {
            if (mvinch(y, x) == blockChar) {
                ++counter;
            }
            if (counter >= width) {
                for (auto iter1 = s.begin(); iter1 != s.end(); ++iter1) {
                    for (auto iter2 = iter1->coords.begin(); iter2 != iter1->coords.end(); ++iter2) {
                        if (iter2->get_y() == y)
                            iter1->coords.erase(iter2);
                    }
                }
            }
        }
        counter = 0;
    }
}

void Game::gameOverChecker() {
    if(s.size() < 2)
        return;
    Structure block = *(s.end() - 2);
    for (auto iter1 = block.coords.cbegin(); iter1 != block.coords.cend(); ++iter1) {
        if (iter1->get_y() <= 1) {
            gameOver = true;
            return;
        }
    }
}

int Game::getSpeed() const {
    return speed;
}

void Game::setSpeed(int speed) {
    Game::speed = speed;
}

bool Game::collision_detector_y(int x, int y) {
    for (auto i1 = s.cbegin(); i1 != s.end() - 1; ++i1)
        for (auto i2 = i1->coords.cbegin(); i2 != i1->coords.cend(); ++i2)
            if (i2->get_y() == y && i2->get_x() == x)
                return true;
    return false;
}

bool Game::collision_detector_x(int x, int y) {
    for (auto i1 = s.cbegin(); i1 != s.end() - 1; ++i1)
        for (auto i2 = i1->coords.cbegin(); i2 != i1->coords.cend(); ++i2)
            if (i2->get_x() == x && i2->get_y() == y)
                return true;
    return false;
}






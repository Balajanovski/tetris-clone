//
// Created by JULIA BALAJAN on 3/12/2016.
//
#include <random>
#include <ncurses.h>
#include "Game.h"
#include <clocale>

int Game::get_next_block() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0,cCoord::max_coordinates);
    int val;
    for (val = distribution(generator); val == prev_block; val = distribution(generator))
    { }
    return val;
}

// Stores template for all the different tetris pieces
const cCoord Game::struct_coords[][cCoord::max_coordinates + 1] = {{
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
const cCoord Game::struct_origins[cCoord::max_coordinates + 1] = {
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
    s.push_back(Structure(get_next_block(), get_next_block()));
}

inline Structure& Game::get_last_block() {
    return *(s.end() - 1);
}

bool Game::isGameOver() const {
    return gameOver;
}

std::vector<Structure>& Game::getStructList() {
    return s;
}

void Game::matrix_init() {
    setlocale(LC_ALL, "");
    initscr();
    start_color();

    init_pair(0, COLOR_GREEN, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    curs_set(FALSE);
    raw();
    noecho();
    nodelay(stdscr, TRUE);

    int x,
        y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            bool foundBlockFlag = false;

            // Cycle through x and y, if x and y match with block, draw block
            for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y()) {
                        attron(COLOR_PAIR(iter1->getColor()));
                        printw("█");
                        attroff(COLOR_PAIR(iter1->getColor()));
                        foundBlockFlag = true;
                        break;
                    }

            // If nothing matches, draw a space
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

            // Cycle through x and y, if there is a block where there isn't a block drawn, draw one
            for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y() && (mvinch(y, x) & A_CHARTEXT) != (blockChar)) {
                        attron(COLOR_PAIR(iter1->getColor()));
                        move(y, x);
                        printw("█");
                        attroff(COLOR_PAIR(iter1->getColor()));
                        foundBlockFlag = true;
                        break;
                    }

            // If nothing matches, draw a space
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
            get_last_block().rotate_left(s);
            break;
        case 'e' : case 'E' :
            get_last_block().rotate_right(s);
            break;
        case 'a' : case 'A' :
            get_last_block().move_left(s);
            break;
        case 'd' : case 'D' :
            get_last_block().move_right(s);
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
    int delete_y;
    bool fall_flag;
    for (int y = height-1; y >= 1; --y) {
        fall_flag = false;
        for (int x = 0; x < width; ++x) {
            if ((mvinch(y, x) & A_CHARTEXT) == (blockChar & A_CHARTEXT)) {
                ++counter;
            }
            if (counter >= width) {
                delete_y = y;
                for (auto iter1 = s.begin(); iter1 != s.end(); ++iter1)
                    for (auto iter2 = iter1->coords.begin(); iter2 != iter1->coords.end();) {
                        if (iter2->get_y() == delete_y) {
                            iter2 = iter1->coords.erase(iter2);
                            fall_flag = true;
                            continue;
                        }
                        ++iter2;
                    }
            }
        }
        if (fall_flag)
            for (int y = delete_y - 1; y >= 0; --y) {
                for (auto iter1 = s.begin(); iter1 != s.end(); ++iter1)
                    for (auto iter2 = iter1->coords.begin(); iter2 != iter1->coords.end(); ++iter2) {
                        if (iter2->get_y() == y)
                            iter2->move_down();
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

bool Game::collision_detector_y(int x, int y, std::vector<Structure> &s) {
    for (auto i1 = s.cbegin(); i1 != s.end() - 1; ++i1)
        for (auto i2 = i1->coords.cbegin(); i2 != i1->coords.cend(); ++i2)
            if (i2->get_y() == y && i2->get_x() == x)
                return true;
    return false;
}

bool Game::collision_detector_x(int x, int y, std::vector<Structure> &s) {
    for (auto i1 = s.cbegin(); i1 != s.end() - 1; ++i1)
        for (auto i2 = i1->coords.cbegin(); i2 != i1->coords.cend(); ++i2)
            if (i2->get_x() == x && i2->get_y() == y)
                return true;
    return false;
}






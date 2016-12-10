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
            std::array<Block, 4>::const_iterator iter2;

            for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
                for (iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y()) {
                        printw("█");
                        break;
                    }
        }
        move(y, x);
        printw("\n");
    }
}

void Game::draw () {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            bool foundBlock = false;
            for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y() && static_cast<char>(mvinch(y, x)) != blockChar) {
                        move(y, x);
                        printw("█");
                        foundBlock = true;
                        break;
                    }

            if (!foundBlock) {
                move(y, x);
                printw(" ");
            }
        }
    }
}

void Game::controls () {
    switch(getch()) {
        case 'a' : case 'A' :
            get_last_block().rotate_left();
            break;
        case 'd' : case 'D' :
            get_last_block().rotate_left();
            break;
    }
}






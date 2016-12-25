//
// Created by JULIA BALAJAN on 3/12/2016.
//
#include <random>
#include "Game.h"

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
    structList.push_back(Structure(get_next_block(), get_next_block()));
}

Structure& Game::get_last_block() {
    return *(structList.end() - 1);
}

bool Game::isGameOver() const {
    return gameOver;
}

std::vector<Structure>& Game::getStructList() {
    return structList;
}

void Game::set_draw_color(const Structure &s) {
    uint8_t color = s.getColor();
    switch (color) {
        case Structure::red :
            SDL_SetRenderDrawColor(ren, 255, 0, 0, SDL_ALPHA_OPAQUE);
            break;
        case Structure::blue :
            SDL_SetRenderDrawColor(ren, 0, 0, 255, SDL_ALPHA_OPAQUE);
            break;
        case Structure::green :
            SDL_SetRenderDrawColor(ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
            break;
        case Structure::yellow :
            SDL_SetRenderDrawColor(ren, 255, 255, 0, SDL_ALPHA_OPAQUE);
            break;
    }
}

void Game::matrix_init() {

    win = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    SDL_Rect screen;
    screen.x = 0;
    screen.y = 0;
    screen.w = screen_width;
    screen.h = screen_height;
    SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(ren, &screen);

    SDL_Rect dest;
    dest.w = tile_size;
    dest.h = tile_size;

    int x,
        y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {

            // Cycle through x and y, if x and y match with block, draw block
            for (auto iter1 = structList.cbegin(); iter1 != structList.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y()) {
                        set_draw_color(*iter1);
                        dest.x = x * tile_size;
                        dest.y = y * tile_size;
                        SDL_RenderFillRect(ren, &dest);
                        SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(ren, &dest);
                        break;
                    }
        }
    }

    SDL_RenderPresent(ren);
}

void Game::draw () {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(ren);
    SDL_Rect dest;
    dest.w = tile_size;
    dest.h = tile_size;

    int x,
        y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {

            // Cycle through x and y, if x and y match with block, draw block
            for (auto iter1 = structList.cbegin(); iter1 != structList.cend(); ++iter1)
                for (auto iter2 = iter1->coords.cbegin(); iter2 != iter1->coords.cend(); ++iter2)
                    if (x == iter2->get_x() && y == iter2->get_y()) {
                        set_draw_color(*iter1);
                        dest.x = x * tile_size;
                        dest.y = y * tile_size;
                        SDL_RenderFillRect(ren, &dest);
                        SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(ren, &dest);
                        break;
                    }
        }
    }

    SDL_RenderPresent(ren);
}

void Game::controls () {
    SDL_PollEvent(&events);
    if (events.type == SDL_KEYDOWN) {
        switch(events.key.keysym.sym) {
            case SDLK_UP :
                get_last_block().rotate_left(structList);
                break;
            case SDLK_DOWN :
                get_last_block().rotate_right(structList);
                break;
            case SDLK_LEFT :
                get_last_block().move_left(structList);
                break;
            case SDLK_RIGHT :
                get_last_block().move_right(structList);
                break;
            case SDLK_SPACE :
                setSpeed(100);
                break;
        }
    }
    if(events.type == SDL_QUIT)
        gameOver = true;
}

void Game::destroy() {
    int counter = 0;
    int delete_y;
    bool fall_flag;
    for (int y = height-1; y >= 1; --y) {
        fall_flag = false;
        for (int x = 0; x < width; ++x) {
            //if ((mvinch(y, x) & A_CHARTEXT) == (blockChar & A_CHARTEXT)) {
            //    ++counter;
            //}
            if (counter >= width) {
                delete_y = y;
                for (auto iter1 = structList.begin(); iter1 != structList.end(); ++iter1)
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
                for (auto iter1 = structList.begin(); iter1 != structList.end(); ++iter1)
                    for (auto iter2 = iter1->coords.begin(); iter2 != iter1->coords.end(); ++iter2) {
                        if (iter2->get_y() == y)
                            iter2->move_down();
                    }
            }

        counter = 0;
    }
}

void Game::gameOverChecker() {
    if(structList.size() < 2)
        return;
    Structure block = *(structList.end() - 2);
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

bool Game::collision_detector_y(int x, int y, std::vector<Structure> &structList) {
    for (auto i1 = structList.cbegin(); i1 != structList.end() - 1; ++i1)
        for (auto i2 = i1->coords.cbegin(); i2 != i1->coords.cend(); ++i2)
            if (i2->get_y() == y && i2->get_x() == x)
                return true;
    return false;
}

bool Game::collision_detector_x(int x, int y, std::vector<Structure> &structList) {
    for (auto i1 = structList.cbegin(); i1 != structList.end() - 1; ++i1)
        for (auto i2 = i1->coords.cbegin(); i2 != i1->coords.cend(); ++i2)
            if (i2->get_x() == x && i2->get_y() == y)
                return true;
    return false;
}






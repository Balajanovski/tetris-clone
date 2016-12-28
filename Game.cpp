//
// Created by JULIA BALAJAN on 3/12/2016.
//
#include <random>
#include <iostream>
#include <algorithm>
#include "Game.h"

uint8_t Game::get_next_block() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0,cCoord::max_coordinates);
    int val;
    for (val = distribution(generator); val == prev_block; val = distribution(generator))
        ;
    return val;
}

uint8_t Game::get_color_value() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 255);\
    return distribution(generator);
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
    structList.push_back(Structure(get_next_block()));
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
    SDL_SetRenderDrawColor(ren, s.red, s.green, s.blue, SDL_ALPHA_OPAQUE);
}

void Game::init() {

    // Initialise SDL_ttf
    if (TTF_Init() == -1) {
        std::cout << "Unable to initialise SDL_ttf: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Create window
    win = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << "Window error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Create renderer
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (ren == nullptr) {
        std::cout << "Renderer error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        exit(1);
    }

    // Create white background
    SDL_Rect screen;
    screen.x = 0;
    screen.y = 0;
    screen.w = screen_width;
    screen.h = screen_height;
    SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(ren, &screen);

    // Initialise font
    constexpr int font_size = 48;
    font = TTF_OpenFont("pixelated.ttf", font_size);
    if (font == nullptr) {
        std::cout << "Font Initialisation Error: " << SDL_GetError() << std::endl;
        cleanup();
        exit(1);
    }

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

    const SDL_Color color = {0, 0, 0};
    SDL_Surface *font_surf = TTF_RenderText_Blended(font, (std::string("Score: ") + std::to_string(score)).c_str(), color);
    if (font_surf == nullptr) {
        std::cout << "Font Rendering Error: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        cleanup();
        exit(1);
    }

    SDL_Texture *font_texture = SDL_CreateTextureFromSurface(ren, font_surf);
    if (font_texture == nullptr) {
        std::cout << "Create Font Texture Error: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_FreeSurface(font_surf);
        cleanup();
        exit(1);
    }

    SDL_FreeSurface(font_surf);

    constexpr int padding = 17;
    int w,
        h;
    SDL_QueryTexture(font_texture, nullptr, nullptr, &w, &h);
    dest.w = w;
    dest.h = h;
    dest.x = screen_width - w - padding;
    dest.y = 0 + padding;

    SDL_RenderCopy(ren, font_texture, nullptr, &dest);

    SDL_RenderPresent(ren);
}

void Game::cleanup() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::controls (unsigned int &last_time) {
    unsigned long current_time = SDL_GetTicks();
    if ((current_time - last_time) > Game::wait_time_controls) {
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
                    while(!get_last_block().move_down(structList))
                        ;
                    break;
                case SDLK_ESCAPE :
                    exit(0);
                    break;
            }
        }
        if(events.type == SDL_QUIT)
            gameOver = true;
        last_time = SDL_GetTicks();
    }
}

void Game::destroy() {
    bool fall_flag          = false;     // Flag to indicate whether the blocks should fall
    bool row_destroyed_flag = false;     // Flag indicating whether a row has been destroyed

    int row_to_destroy;         // Y value indicating the row to be destroyed
    int row_counter[height];    // Counter, to know which row to destroy
    int rows_been_destroyed = 0; // Count of how many rows have been destroyed to be used when calculating fall distance

    do {
        row_destroyed_flag = false;
        // Set the counter to 0
        std::fill(std::begin(row_counter), std::end(row_counter), 0);

        // Iterate through all the blocks, check if there are any complete rows, if so, destroy them
        for (auto &s : structList)
            for (auto &b : s.coords) {
                // If there is a complete row
                if (++row_counter[row_to_destroy = b.get_y()] >= width) {
                    // Destroy the blocks in the row
                    ++rows_been_destroyed;
                    for (auto &s : structList)
                        for (auto block_iter = s.coords.begin(); block_iter != s.coords.end();) {
                            if (block_iter->get_y() == row_to_destroy) {
                                block_iter = s.coords.erase(block_iter);
                                fall_flag = row_destroyed_flag = true;
                                continue;
                            }
                            ++block_iter;
                        }
                }
            }
    } while (row_destroyed_flag); // Re-iterate if a row was destroyed

    if (rows_been_destroyed <= 4)
        score += (100 * rows_been_destroyed);
    else if (rows_been_destroyed > 4)
        score += (200 * rows_been_destroyed);

    // If blocks have been destroyed, make the blocks above fall
    if (fall_flag) {
        // Iterate through the blocks, making the blocks above the destroyed row fall
        for (auto &s : structList)
            for (auto &b : s.coords)
                if (b.get_y() <= row_to_destroy)
                    b.move_down(rows_been_destroyed); // Fall by how many rows have been destroyed
    }
}

void Game::gameOverChecker() {
    if(structList.size() < 2)
        return;
    Structure block = *(structList.end() - 2);
    for (auto iter1 = block.coords.cbegin(); iter1 != block.coords.cend(); ++iter1) {
        if (iter1->get_y() <= 1) {
            gameOver = true;
            cleanup();
            return;
        }
    }
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







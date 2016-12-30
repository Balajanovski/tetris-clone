//
// Created by JULIA BALAJAN on 3/12/2016.
//
#include <random>
#include <iostream>
#include <algorithm>
#include <cstring>
#include "Game.h"

uint8_t Game::get_next_block() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0,6);
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
const cCoord Game::struct_coords[][cCoord::max_coordinates] = {{
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
                                          },
                                          {
                                                  /* Row: 1 */ {0, 0}, {1, 0}, {2, 0},
                                                  /* Row: 2 */                 {2, 1},
                                          },
                                          {
                                                  /* Row: 1 */ {0, 0}, {1, 0},
                                                  /* Row: 2 */         {1, 1}, {2, 1},
                                          }};

// Stores the origins coords for all the different tetris pieces
const cCoord Game::struct_origins[] = {
        /* L Shaped */              {0, 0},
        /* Square shaped */         {0, 0},
        /* Stick shaped */          {0, 0},
        /* Stair shaped */          {1, 0},
        /* T shaped */              {1, 1},
        /* Reverse L shaped */      {2, 0},
        /* Reverse Stair shaped */  {1, 0},
};

Game::Game() {
    create_block();
    std::memset(matrix, NULL, sizeof(matrix[0][0]) * height * width);
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
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cout << "Unable to initialise SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Initialise SDL_ttf
    if (TTF_Init() == -1) {
        std::cout << "Unable to initialise SDL_ttf: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Initalise SDL_Mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        std::cout << "Unable to initialise SDL_mixer: " << SDL_GetError() << std::endl;
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

    // Load music
    music = Mix_LoadMUS("Tetris_Theme_B.wav");
    if (music == nullptr) {
        std::cout << "Music Initialisation Error: " << SDL_GetError() << std::endl;
        cleanup();
        exit(1);
    }

    Mix_PlayMusic(music, -1);

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
                        // Set the draw color
                        set_draw_color(*iter1);

                        // Position the rectangle to draw
                        dest.x = x * tile_size;
                        dest.y = y * tile_size;

                        // Fill the rectangle
                        SDL_RenderFillRect(ren, &dest);

                        // Set color to black, then draw a border around the block
                        SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(ren, &dest);
                        break;
                    }
        }
    }

    // Color for drawing the score
    const SDL_Color color = {0, 0, 0};

    // Create font surface
    SDL_Surface *font_surf = TTF_RenderText_Blended(font, (std::string("Score: ") + std::to_string(score)).c_str(), color);
    if (font_surf == nullptr) {
        std::cout << "Font Rendering Error: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        cleanup();
        exit(1);
    }

    // Create texture from font surface
    SDL_Texture *font_texture = SDL_CreateTextureFromSurface(ren, font_surf);
    if (font_texture == nullptr) {
        std::cout << "Create Font Texture Error: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_FreeSurface(font_surf);
        cleanup();
        exit(1);
    }

    // Destroy the surface since we don't need it anymore
    SDL_FreeSurface(font_surf);


    constexpr int margin = 17;
    int w,
        h;

    // Query font texture for width and height
    SDL_QueryTexture(font_texture, nullptr, nullptr, &w, &h);

    // Create rectangle to draw to
    dest.w = w;
    dest.h = h;
    dest.x = screen_width - w - margin;
    dest.y = 0 + margin;

    // Draw the score
    SDL_RenderCopy(ren, font_texture, nullptr, &dest);

    // Present all changes
    SDL_RenderPresent(ren);
}

void Game::cleanup() {
    TTF_CloseFont(font);
    TTF_Quit();
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
                    for (auto &b : get_last_block().coords)
                        matrix[b.get_x()][b.get_y()] = &b;
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
    bool row_destroyed_flag = false;     // Flag indicating whether a row has been destroyed

    int rows_been_destroyed = 0; // Count of how many rows have been destroyed to be used when calculating fall distance

    int counter; // To count blocks to check for a completed row

    do  {
        row_destroyed_flag = false;
        for (int y = height - 1; y >= 0; --y) {
            counter = 0;
            for (int x = 0; x < width; ++x) {
                if (matrix[x][y] != nullptr)
                    ++counter;
                if (counter >= width) {
                    ++rows_been_destroyed;
                    row_destroyed_flag = true;
                    for (int i = 0; i < width; ++i)
                        matrix[i][y] = nullptr;
                    for (auto &s : structList)
                        for (auto iter = s.coords.begin(); iter != s.coords.end();) {
                            if (iter->get_y() == y) {
                                iter = s.coords.erase(iter);
                            }
                            else
                                ++iter;
                        }

                    // The blocks shall fall!!!
                    for (auto &s : structList)
                        for (auto &b : s.coords)
                            if (b.get_y() < y) {
                                matrix[b.get_x()][b.get_y()] = nullptr;
                                b.move_down(); // Fall by how many rows have been destroyed
                                matrix[b.get_x()][b.get_y()] = &b;
                            }
                }
            }
        }
    } while (row_destroyed_flag);


    if (rows_been_destroyed <= 4)
        score += (100 * rows_been_destroyed);
    else if (rows_been_destroyed > 4)
        score += (200 * rows_been_destroyed);

}

void Game::gameOverChecker() {
    if(structList.size() < 2)
        return;
    Structure block = *(structList.end() - 2);
    for (auto iter1 = block.coords.cbegin(); iter1 != block.coords.cend(); ++iter1) {
        if (iter1->get_y() <= 1) {
            gameOver = true;
            Mix_HaltMusic();
            Mix_FreeMusic(music);
            Mix_CloseAudio();
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









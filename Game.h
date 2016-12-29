//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Structure.h"
#include <vector>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

class Game {
friend class Controller;
private:
    int prev_block = 99; /* Previous block, represented by the key */
    bool gameOver = false;
    std::vector<Structure> structList; /* Contains all the structures that have fallen, and are currently falling */
    int score = 0;

    // SDL methods and variables
    SDL_Event events; // Event queue

    SDL_Window *win = nullptr;
    SDL_Renderer *ren = nullptr;

    TTF_Font *font = nullptr;

    void set_draw_color(const Structure &s);
    void cleanup();

public:
    /*
     * Block structures key:
     * 0 : L shaped
     * 1 : Square shaped
     * 2 : Stick shaped
     * 3 : Stair shaped
     * 4 : T shaped
     * 5 : Reverse L shaped
     * 6 : Reversed Stair shaped
     */
    const int default_speed = 300;

    // Height/width not in terms of pixels but in terms of blocks
    constexpr static int height = 25;
    constexpr static int width = 10;

    static const cCoord struct_coords[][cCoord::max_coordinates];
    static const cCoord struct_origins[];

    Game(); /* Constructor */

    // Block/Structure functions
    void create_block();
    Structure& get_last_block();
    void destroy(); // Destroy blocks in a line and then make all blocks ontop fall down
    static bool collision_detector_y(int x, int y, std::vector<Structure> &structList);
    static bool collision_detector_x(int x, int y, std::vector<Structure> &structList);

    // Getters
    bool isGameOver() const;
    std::vector<Structure> &getStructList();

    // General game methods
    void init();
    void draw();
    void controls(unsigned int &last_time);
    void gameOverChecker();

    // Random number generators
    uint8_t get_next_block();
    static uint8_t get_color_value(); // Generates a number from 0 - 255 which will be used when generating block colors

    // Regulate speed
    static constexpr int wait_time_down     = 500; // Wait time for the block to fall
    static constexpr int wait_time_controls = 125; // Wait time for the controls
private:
    // SDL Constants put in their own private little corner because they hate co-operation, kinda like co-workers
    constexpr static int tile_size = 40;
    constexpr static int screen_width = width * tile_size;
    constexpr static int screen_height = height * tile_size;
};


#endif //TETRIS_GAME_H

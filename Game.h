//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Structure.h"
#include <vector>
#include <SDL2/SDL.h>

class Game {
friend class Controller;
private:
    int prev_block = 99; /* Previous block, represented by the key */
    bool gameOver = false;
    int speed = 250;
    std::vector<Structure> structList; /* Contains all the structures that have fallen, and are currently falling */

    // Graphics
    constexpr static int screen_width = 400;
    constexpr static int screen_height = 960;
    constexpr static int tile_size = 40;

    // Event Queue
    SDL_Event events;

    void set_draw_color(const Structure &s);
    SDL_Window *win = nullptr;
    SDL_Renderer *ren = nullptr;
public:
    /*
     * Block structures key:
     * 0 : L shaped
     * 1 : Square shaped
     * 2 : Stick shaped
     * 3 : Stair shaped
     * 4 : T shaped
     */
    const int default_speed = 300;

    // In terms of blocks
    constexpr static int height = 24;
    constexpr static int width = 10;

    static const cCoord struct_coords[][cCoord::max_coordinates + 1];
    static const cCoord struct_origins[cCoord::max_coordinates + 1];

    Game(); /* Constructor */

    // Block/Structure functions
    void create_block();
    Structure& get_last_block();
    void destroy(); // Destroy blocks in a line and then make all blocks ontop fall down
    static bool collision_detector_y(int x, int y, std::vector<Structure> &structList);
    static bool collision_detector_x(int x, int y, std::vector<Structure> &structList);

    // Getters
    int get_next_block();
    bool isGameOver() const;
    int getSpeed() const;
    std::vector<Structure> &getStructList();

    // Setters
    void setSpeed(int speed);

    // General game methods
    void matrix_init();
    void draw();
    void controls();
    void gameOverChecker(); // Checks for game over
};


#endif //TETRIS_GAME_H

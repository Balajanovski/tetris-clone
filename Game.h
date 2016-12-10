//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Structure.h"
#include <vector>

class Game {
private:
    int highest_level; /* The highest point in the map */
    int prev_block = 99; /* Previous block, represented by the key */\
    std::vector<Structure> s;
    bool gameOver;
public:
    /*
     * Block structures key:
     * 0 : L shaped
     * 1 : Square shaped
     * 2 : Stick shaped
     * 3 : Stair shaped
     * 4 : T shaped
     */
    const static int height = 20;
    const static int width = 10;

    const static long blockChar = L'\u2588'; /* Constant which represents the value of the block character */

    static cCoord struct_coords[][MAX_COORDINATES + 1];
    static cCoord struct_origins[MAX_COORDINATES + 1];

    Game(); /* Constructor */

    // Block/Structure functions
    void create_block();
    Structure& get_last_block();

    // Getters
    int get_next_block();
    bool isGameOver() const;

    // General game methods
    void matrix_init();
    void draw();
    void controls();
};


#endif //TETRIS_GAME_H

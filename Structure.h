//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_STRUCTURE_H
#define TETRIS_STRUCTURE_H

#include "cCoord.h"
#include "Block.h"
#include <array>

class Structure {
    private:
        int struct_type; // The type of block, according to the key
        cCoord origin;
    public:
        Structure(int type);

        Structure rotate_left();
        Structure rotate_right();

        Structure move_down();
        Structure move_left();
        Structure move_right();

        bool can_move_right = true;
        bool can_move_left = true;

        std::array<Block, 4> coords;
};


#endif //TETRIS_STRUCTURE_H

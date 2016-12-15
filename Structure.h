//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_STRUCTURE_H
#define TETRIS_STRUCTURE_H

#include "cCoord.h"
#include "Block.h"
#include <vector>

class Structure {
    private:
        int struct_type; // The type of block, according to the key
        cCoord origin;
    public:
        Structure(int type);
        Structure(const Structure&);
        ~Structure() = default;

        Structure rotate_left();
        Structure rotate_right();

        bool move_down();
        Structure move_left();
        Structure move_right();

        bool can_move_right = true;
        bool can_move_left = false;

        std::vector<Block> coords;
};


#endif //TETRIS_STRUCTURE_H

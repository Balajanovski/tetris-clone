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
        int color;
    public:
        Structure(int type, int c);
        Structure(const Structure&);

        // Rotation methods
        Structure rotate_left();
        Structure rotate_right();

        // Movement methods
        bool move_down();
        Structure move_left();
        Structure move_right();

        std::vector<Block> coords;

        // Getters
        int getColor() const;
};


#endif //TETRIS_STRUCTURE_H

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

        // Constants used by rotate_point() (in radians)
        constexpr static int sin_right = -1;
        constexpr static int cos_right = 0;
        constexpr static int sin_left = 1;
        constexpr static int cos_left = 0;

        // Constants defining direction used by rotate_point()
        constexpr static int right = 1;
        constexpr static int left = 0;

        // Rotation methods
        Structure rotate_left(std::vector<Structure> &structList);
        Structure rotate_right(std::vector<Structure> &structList);

        // Movement methods
        bool move_down(std::vector<Structure> &structList);
        Structure move_left(std::vector<Structure> &structList);
        Structure move_right(std::vector<Structure> &structList);

        std::vector<Block> coords;

        // RGB
        const uint8_t red;
        const uint8_t green;
        const uint8_t blue;

};


#endif //TETRIS_STRUCTURE_H

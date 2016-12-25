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
        uint8_t color;
    public:
        Structure(int type, int c);
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

        // Color constants
        constexpr static int red = 0;
        constexpr static int blue = 1;
        constexpr static int green = 2;
        constexpr static int yellow = 3;

        std::vector<Block> coords;

        // Getters
        int getColor() const;
};


#endif //TETRIS_STRUCTURE_H

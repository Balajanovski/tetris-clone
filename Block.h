//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include "cCoord.h"

class Block {
private:
    cCoord coord;
public:
    Block(cCoord c);
    Block(int x, int y);
    Block() = default;

    ~Block() = default;

    void move_down();
    void move_right();
    void move_left();

    // Setter functions
    Block set_x(int x) { coord.set_x(x); return *this; }
    Block set_y(int y) { coord.set_y(y); return *this; }

    // Getter functions
    int get_x() const { return coord.get_x(); }
    int get_y() const { return coord.get_y(); }
};


#endif //TETRIS_BLOCK_H

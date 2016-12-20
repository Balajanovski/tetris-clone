//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_CCOORD_H
#define TETRIS_CCOORD_H

#define MAX_COORDINATES  4

struct cCoord {
    int x,
        y;

    cCoord(int a, int b) : x(a), y(b) {};
    cCoord() = default;
    ~cCoord() = default;
};


#endif //TETRIS_CCOORD_H

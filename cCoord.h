//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_CCOORD_H
#define TETRIS_CCOORD_H



struct cCoord {
    int x,
        y;

    constexpr static int max_coordinates = 4;

    cCoord(int a, int b) : x(a), y(b) {};
    cCoord() = default;
    ~cCoord() = default;
};


#endif //TETRIS_CCOORD_H

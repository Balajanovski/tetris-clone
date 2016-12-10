//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_CCOORD_H
#define TETRIS_CCOORD_H

#define MAX_COORDINATES  4

class cCoord {
private:
    int x,
        y;
public:
        // Getter functions
    int get_x() const;
    int get_y() const;

    // Setter functions
    cCoord set_x(int a);
    cCoord set_y(int b);

    cCoord(int a, int b) : x(a), y(b) {};
    cCoord() = default;
    ~cCoord() = default;
};


#endif //TETRIS_CCOORD_H

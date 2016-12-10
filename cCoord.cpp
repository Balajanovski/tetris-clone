//
// Created by JULIA BALAJAN on 3/12/2016.
//

#include "cCoord.h"

int cCoord::get_x() const {
    return x;
}

int cCoord::get_y() const {
    return y;
}

cCoord cCoord::set_y(int b) {
    y = b;
    return *this;
}

cCoord cCoord::set_x(int a) {
    x = a;
    return *this;
}



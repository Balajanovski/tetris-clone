//
// Created by JULIA BALAJAN on 3/12/2016.
//

#include "Block.h"
#include "Game.h"
#include <ncurses.h>

Block::Block(cCoord c) : coord(c) {}

Block::Block(int x, int y) : coord(x, y) {}

void Block::move_down() {
    coord.set_y(coord.get_y() + 1);
}

void Block::move_right() {
    coord.set_x(coord.get_x() + 1);
}
void Block::move_left() {
    coord.set_x(coord.get_x() - 1);
}
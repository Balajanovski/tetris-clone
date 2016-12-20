//
// Created by JULIA BALAJAN on 3/12/2016.
//

#include "Block.h"
#include "Game.h"

Block::Block(cCoord c) : coord(c) {}

Block::Block(int x, int y) : coord(x, y) {}

void Block::move_down() {
    coord.y += 1;
}

void Block::move_right() {
    coord.x += 1;
}
void Block::move_left() {
    coord.x -= 1;
}
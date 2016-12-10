//
// Created by JULIA BALAJAN on 3/12/2016.
//

#include "Block.h"
#include "Game.h"

Block::Block(cCoord c) : coord(c) {}

Block::Block(int x, int y) : coord(x, y) {}

void Block::move_down() {
    if (coord.get_y() >= Game::height - 1)
        return;
    coord.set_y(coord.get_y() + 1);
}
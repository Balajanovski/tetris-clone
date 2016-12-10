//
// Created by JULIA BALAJAN on 3/12/2016.
//
#include <cmath>
#include "Structure.h"
#include "Game.h"

inline void rotate_point(cCoord &origin, float angle, Block &p) {
    int x1 = static_cast<int>(round(cos(angle) * (p.get_x() - origin.get_x()) - sin(angle) * (p.get_y() - origin.get_y()) + origin.get_x()));
    int y1 = static_cast<int>(round(cos(angle) * (p.get_y() - origin.get_y()) + sin(angle) * (p.get_x() - origin.get_x()) + origin.get_y()));

    p.set_x(x1);
    p.set_y(y1);
}

Structure::Structure(int type) : struct_type(type), origin(Game::struct_origins[type]) {
    for (int i = 0; i < MAX_COORDINATES; ++i) {
        coords.at(i).set_x(Game::struct_coords[type][i].get_x());
        coords.at(i).set_y(Game::struct_coords[type][i].get_y());
    }
}

Structure Structure::rotate_left() {
    for (auto &c : coords)
        rotate_point(origin, 1.5708, c);
    return *this;
}

Structure Structure::rotate_right() {
    for (auto &c : coords)
        rotate_point(origin, -1.5708, c);
    return *this;
}

Structure Structure::move_down() {
    for (auto &c : coords)
        c.move_down();
    if (!(origin.get_y() >= Game::height - 1))
        origin.set_y(origin.get_y() + 1);
    return *this;
}

Structure Structure::move_left() {
    if (!can_move_left)
        return *this;
    bool cannot_move_left_flag = false;
    bool cannot_move_right_flag = false;
    for (auto &c : coords) {
        c.move_left();
        if (c.get_x() <= 0) {
            can_move_left = false;
            cannot_move_left_flag = true;
        }
        if (c.get_x() >= Game::width - 1) {
            can_move_right = false;
            cannot_move_right_flag = true;
        }
    }
    if (!cannot_move_left_flag)
        can_move_left = true;
    if (!cannot_move_right_flag)
        can_move_right = true;
    origin.set_x(origin.get_x() - 1);
    return *this;
}

Structure Structure::move_right() {
    if (!can_move_right)
        return *this;
    bool cannot_move_left_flag = false;
    bool cannot_move_right_flag = false;
    for (auto &c : coords) {
        c.move_right();
        if (c.get_x() <= 0) {
            can_move_left = false;
            cannot_move_left_flag = true;
        }
        if (c.get_x() >= Game::width - 1) {
            can_move_right = false;
            cannot_move_right_flag = true;
        }
    }
    if (!cannot_move_left_flag)
        can_move_left = true;
    if (!cannot_move_right_flag)
        can_move_right = true;
    origin.set_x(origin.get_x() + 1);
    return *this;
}

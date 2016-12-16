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

Structure::Structure(int type, int c) : struct_type(type), origin(Game::struct_origins[type]), color(c) {
    coords.resize(4);
    for (int i = 0; i < MAX_COORDINATES; ++i) {
        coords.at(i).set_x(Game::struct_coords[type][i].get_x());
        coords.at(i).set_y(Game::struct_coords[type][i].get_y());
    }
}

Structure::Structure(const Structure &s) : struct_type(s.struct_type), origin(s.origin), coords(s.coords), color(s.color) {}

Structure Structure::rotate_left() {
    std::vector<Block> temp(coords);    // Create a temporary array to make
                                        // sure the structure doesn't go out of bounds
    for (auto &b : temp) {
        rotate_point(origin, 1.5708, b);

        // If out of bounds, do not rotate the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || b.get_y() > Game::height - 1 || b.get_y() < 0 || Game::collision_detector_x(b.get_x(), b.get_y()))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    return *this;
}

Structure Structure::rotate_right() {
    std::vector<Block> temp(coords);    // Create a temporary array to make
                                        // sure the structure doesn't go out of bounds
    for (auto &b : temp) {
        rotate_point(origin, -1.5708, b);

        // If out of bounds, do not rotate the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || b.get_y() > Game::height - 1 || b.get_y() < 0 || Game::collision_detector_x(b.get_x(), b.get_y()))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    return *this;
}

bool Structure::move_down() {
    for (auto &b : coords) {
        if (b.get_y() >= Game::height - 1 || Game::collision_detector_y(b.get_x(), b.get_y() + 1))
            return true;
    }
    for (auto &b : coords)
        b.move_down();
    if (origin.get_y() <= Game::height - 1)
        origin.set_y(origin.get_y() + 1);
    return false;
}

Structure Structure::move_left() {
    std::vector<Block> temp(coords);    // Create a temporary array to make sure the
                                        // structure doesn't go out of bounds

    for (auto &b : temp) {
        b.move_left();

        // If out of bounds, do not move the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || Game::collision_detector_x(b.get_x() - 1, b.get_y()))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    origin.set_x(origin.get_x() - 1);
    return *this;
}

Structure Structure::move_right() {
    std::vector<Block> temp(coords);    // Create a temporary array to make sure the
                                        // structure doesn't go out of bounds

    for (auto &b : temp) {
        b.move_right();

        // If out of bounds, do not move the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || Game::collision_detector_x(b.get_x() + 1, b.get_y()))
        return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    origin.set_x(origin.get_x() + 1);
    return *this;
}

int Structure::getColor() const {
    return color;
}

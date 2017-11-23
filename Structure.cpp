//
// Created by Balajanovski on 3/12/2016.
//
#include "Structure.h"
#include "Game.h"

inline void rotate_point(cCoord &origin, int direction, Block &p) {
    int x1,
        y1;

    if (direction == Structure::left) {
        x1 = Structure::cos_left * (p.get_x() - origin.x) - Structure::sin_left * (p.get_y() - origin.y) + origin.x;
        y1 = Structure::cos_left * (p.get_y() - origin.y) + Structure::sin_left * (p.get_x() - origin.x) + origin.y;
    }

    else if(direction == Structure::right) {
        x1 = Structure::cos_right * (p.get_x() - origin.x) - Structure::sin_right * (p.get_y() - origin.y) + origin.x;
        y1 = Structure::cos_right * (p.get_y() - origin.y) + Structure::sin_right * (p.get_x() - origin.x) + origin.y;
    }

    p.set_x(x1);
    p.set_y(y1);
}

Structure::Structure(int type) : struct_type(type), origin(cCoord(Game::struct_origins[type].x + Game::width / 2 - 2, Game::struct_origins[type].y)), red(Game::get_color_value()),
                                 green(Game::get_color_value()), blue(Game::get_color_value())
{
    coords.resize(4);
    for (int i = 0; i < cCoord::max_coordinates; ++i) {
        coords.at(i).set_x(Game::struct_coords[type][i].x + Game::width / 2 - 2);
        coords.at(i).set_y(Game::struct_coords[type][i].y);
    }
}

Structure::Structure(const Structure &s) : struct_type(s.struct_type), origin(s.origin), coords(s.coords), red(s.red), green(s.green), blue(s.blue) {}

Structure Structure::rotate_left(std::vector<Structure> &structList) {
    std::vector<Block> temp(coords);    // Create a temporary array to make
                                        // sure the structure doesn't go out of bounds
    for (auto &b : temp) {
        rotate_point(origin, Structure::left, b);

        // If out of bounds, do not rotate the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || b.get_y() > Game::height - 1 || b.get_y() < 0 || Game::collision_detector_x(b.get_x(), b.get_y(), structList))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    return *this;
}

Structure Structure::rotate_right(std::vector<Structure> &structList) {
    std::vector<Block> temp(coords);    // Create a temporary array to make
                                        // sure the structure doesn't go out of bounds
    for (auto &b : temp) {
        rotate_point(origin, Structure::right, b);

        // If out of bounds, do not rotate the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || b.get_y() > Game::height - 1 || b.get_y() < 0 || Game::collision_detector_x(b.get_x(), b.get_y(), structList))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    return *this;
}

bool Structure::move_down(std::vector<Structure> &structList) {
    for (auto &b : coords) {
        if (b.get_y() >= Game::height - 1 || Game::collision_detector_y(b.get_x(), b.get_y() + 1, structList))
            return true; // Cannot move any further
    }
    for (auto &b : coords)
        b.move_down();
    if (origin.y <= Game::height - 1)
        origin.y += 1;
    return false;
}

Structure Structure::move_left(std::vector<Structure> &structList) {
    std::vector<Block> temp(coords);    // Create a temporary array to make sure the
    // structure doesn't go out of bounds

    for (auto &b : temp) {
        b.move_left();

        // If out of bounds, do not move the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || Game::collision_detector_x(b.get_x(), b.get_y(), structList))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    origin.x -= 1;
    return *this;
}

Structure Structure::move_right(std::vector<Structure> &structList) {
    std::vector<Block> temp(coords);    // Create a temporary array to make sure the
                                        // structure doesn't go out of bounds

    for (auto &b : temp) {
        b.move_right();

        // If out of bounds, do not move the original structure
        if (b.get_x() > Game::width - 1 || b.get_x() < 0 || Game::collision_detector_x(b.get_x(), b.get_y(), structList))
            return *this;
    }
    for (int i = 0; i < coords.size(); ++i)
        coords[i] = temp[i];
    origin.x += 1;
    return *this;
}

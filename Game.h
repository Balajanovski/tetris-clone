//
// Created by JULIA BALAJAN on 3/12/2016.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Structure.h"
#include <vector>

class Game {
friend class Block;
private:
    int prev_block = 99; /* Previous block, represented by the key */
    bool gameOver = false;
    int speed = 250;
    std::vector<Structure> s;
public:
    /*
     * Block structures key:
     * 0 : L shaped
     * 1 : Square shaped
     * 2 : Stick shaped
     * 3 : Stair shaped
     * 4 : T shaped
     */
    const int default_speed = 300;
    constexpr static int height = 24;
    constexpr static int width = 10;

    constexpr static long blockChar = L'\u2588'; /* Constant which represents the value of the block character */

    static const cCoord struct_coords[][MAX_COORDINATES + 1];
    static const cCoord struct_origins[MAX_COORDINATES + 1];

    Game(); /* Constructor */

    // Block/Structure functions
    void create_block();
    Structure& get_last_block();
    void destroy(); // Destroy blocks in a line and then make all blocks ontop fall down
    static bool collision_detector_y(int x, int y, std::vector<Structure> &s);
    static bool collision_detector_x(int x, int y, std::vector<Structure> &s);

    // Getters
    int get_next_block();
    bool isGameOver() const;
    int getSpeed() const;
    std::vector<Structure> &getStructList();

    // Setters
    void setSpeed(int speed);

    // General game methods
    void matrix_init();
    void draw();
    void controls();
    void gameOverChecker(); // Checks for game over
};


#endif //TETRIS_GAME_H

#include "Game.h"
#include <ncurses.h>
#include <clocale>

void redraw() {

}

int main() {
    Game game;
    setlocale(LC_ALL, "");
    initscr();

    raw();
    noecho();
    nodelay(stdscr, TRUE);

    while (!game.isGameOver()) {
        game.matrix_init();
        game.get_last_block().move_down();
        game.controls();
    }
    return 0;
}
#include "Game.h"
#include <ncurses.h>
#include <clocale>

int main() {
    Game game;
    setlocale(LC_ALL, "");
    initscr();

    curs_set(FALSE);
    raw();
    noecho();
    nodelay(stdscr, TRUE);

    game.matrix_init();

    while (!game.isGameOver()) {
        bool can_create_block = false;
        can_create_block = game.get_last_block().move_down();
        if (can_create_block) {
            game.destroy();
            game.create_block();
        }
        game.controls();
        napms(game.getSpeed());
        if (game.getSpeed() < DEFAULT_SPEED)
            game.setSpeed(DEFAULT_SPEED);
        game.draw();
        game.gameOverChecker();
        refresh();
    }
    endwin();
    return 0;
}
#include "Game.h"

int main() {
    Game game;
    game.matrix_init();

    while (!game.isGameOver()) {
        bool can_create_block = false;
        can_create_block = game.get_last_block().move_down(game.getStructList());
        if (can_create_block) {
            game.destroy();
            game.create_block();
        }
        game.controls();
        SDL_Delay(game.getSpeed());
        if (game.getSpeed() < game.default_speed)
            game.setSpeed(game.default_speed);
        game.draw();
        game.gameOverChecker();
    }
    SDL_Quit();
}
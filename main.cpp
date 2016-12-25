#include "Game.h"
#include <iostream>

int main() {
    constexpr int8_t max_fps = 60;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << "Unable to initialise SDL: " << SDL_GetError();

    Game game;
    game.init();

    int lastTicks = 0;
    while (!game.isGameOver()) {

        bool can_create_block = false;
        can_create_block = game.get_last_block().move_down(game.getStructList());
        if (can_create_block) {
            game.destroy();
            game.create_block();
        }

        int current_ticks = SDL_GetTicks();
        int delay = 1000 / max_fps - current_ticks + lastTicks;

        if(delay > 0)
            SDL_Delay(delay);
        game.controls();
        game.draw();
        game.gameOverChecker();

        lastTicks = current_ticks;
    }

}
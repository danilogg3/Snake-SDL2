#define SDL_MAIN_HANDLED
// Using SDL and standard IO
#include <iostream>
#include <windows.h>
#include "game.h"

int main() {
    Game game;
    game.loop();
    return 0;
}


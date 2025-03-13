#define SDL_MAIN_HANDLED
// Using SDL and standard IO
#include <iostream>
#include <windows.h>
#include "game.h"

int main() {
    std::cout << "e agora?" << std::endl;
    Game game;
    std::cout << "começou" << std::endl;
    game.loop();
    std::cout << "Acabou" << std::endl;
    return 0;
}


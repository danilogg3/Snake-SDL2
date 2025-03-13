#define SDL_MAIN_HANDLED
// Using SDL and standard IO
#include <SDL.h>
#include <iostream>
#include <windows.h>
#include "game.h"

int main() {
    Game game;

    SDL_Surface* windowSurface = SDL_GetWindowSurface(game.window);
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(game.windowSurface->format, 255,90,120));
    SDL_BlitSurface( game.image, NULL, game.windowSurface, NULL );
    SDL_UpdateWindowSurface(game.window);
    SDL_Delay(8000);
    return 0;
}


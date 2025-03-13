#include <SDL.h>
#include <iostream>

class Game
{
private:
    /* data */
public:
    SDL_Window* window = nullptr;
    SDL_Surface* load = nullptr;
    SDL_Surface* windowSurface = nullptr;
    SDL_Surface* image = nullptr;
    Game(/* args */);
    ~Game();
};

Game::Game(/* args */)
{
    std::cout << "Creating Window" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Snake Game", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if ( !window )
    {
        std::cout << "Failed to create a window! Error" << SDL_GetError() << std::endl;
    }
    windowSurface = SDL_GetWindowSurface(window);
    load = SDL_LoadBMP("../img/test.bmp");
    if (!image)
    {
        std::cout << "Failed to Load image surface! Error" << SDL_GetError() << std::endl;
    }
    image = SDL_ConvertSurface( load, windowSurface->format, 0 );
    
}

Game::~Game()
{
    std::cout << "Destroing Window" << std::endl;
    SDL_DestroyWindow(window);
    window = nullptr;
    windowSurface = nullptr;
    image = nullptr;
    SDL_FreeSurface(image);
    SDL_FreeSurface(windowSurface);
    SDL_Quit();
}

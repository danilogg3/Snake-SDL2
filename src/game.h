#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

class Game
{
private:
    bool isRunning = true;
public:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* load = nullptr;
    SDL_Texture* image = nullptr;
    Game(/* args */);
    ~Game();
    void loop();
    void createTexture(const char*);
};


#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

class Game
{
private:
    bool isRunning = true;
public:
    int mousePos = 0;
    SDL_Rect redHealthBar{102,102,196};
    SDL_Rect rect{100, 100, 200, 22};
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* load = nullptr;
    SDL_Texture* image = nullptr;
    SDL_Texture* heart = nullptr;
    SDL_Texture* healthBar = nullptr;
    Game(/* args */);
    ~Game();
    void loop();
    void createTexture(const char*, SDL_Texture*&);
    void loadImages();
    void render();
};


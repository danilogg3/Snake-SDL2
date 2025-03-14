#include "game.h"
Game::Game(/* args */)
{
    std::cout << "Creating Window" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        std::cout << "ERROR SDL2_image Initialization";
    }
    
    //Create Window
    window = SDL_CreateWindow("Snake Game", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if ( !window )
    {
        std::cout << "Failed to create a window! Error" << SDL_GetError() << std::endl;
    }
    //Create Renderer 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if ( !renderer )
    {
        std::cout << "Failed to create a renderer! Error" << SDL_GetError() << std::endl;
    }

    loadImages();
}

void Game::loop()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    while (isRunning)
    {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
            if(e.type == SDL_MOUSEMOTION) {
                mousePos = e.motion.x;
                
                if(mousePos < 196)
                    mousePos = 196;
                
                if(mousePos > 392)
                    mousePos = 392;
            }
        }
        render();
    }
    
}

void Game::createTexture(const char* PATH, SDL_Texture*& imageAddr)
{   
    load = IMG_Load(PATH);
    if (load ==nullptr)
    {
        std::cout << "ERROR loading image:" << std::endl;
    }
    
    imageAddr = SDL_CreateTextureFromSurface(renderer, load);
    if (imageAddr == nullptr) {
        std::cout << "Error creating texture";
    }
    SDL_FreeSurface(load);
}

void Game::loadImages()
{
    createTexture("../img/PNG/Learning/Bar.png", healthBar);
}

void Game::render()
{
    redHealthBar = {102,102,(mousePos-196), 18};
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, healthBar, nullptr, &rect);
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderFillRect(renderer, &redHealthBar);
    SDL_RenderPresent(renderer);
}
Game::~Game()
{
    std::cout << "Destroing Window" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(image);
    SDL_DestroyTexture(heart);
    SDL_DestroyTexture(healthBar);


    window = nullptr;
    image = nullptr;
    IMG_Quit();
    SDL_Quit();
}
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
}

void Game::loop()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    while (isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                createTexture("../img/PNG/Slime1/idle/Slime1_Idle_full.png");
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, image, nullptr, nullptr);
                SDL_RenderPresent(renderer);
            }
            
            
        }
    }
    
}

void Game::createTexture(const char* PATH)
{   
    load = IMG_Load(PATH);
    if (load ==nullptr)
    {
        std::cout << "ERROR loading image:" << std::endl;
    }
    
    image = SDL_CreateTextureFromSurface(renderer, load);
    if (image == NULL) {
        std::cout << "Error creating texture";
    }
    SDL_FreeSurface(load);
}

Game::~Game()
{
    std::cout << "Destroing Window" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(image);

    window = nullptr;
    image = nullptr;
    IMG_Quit();
    SDL_Quit();
}
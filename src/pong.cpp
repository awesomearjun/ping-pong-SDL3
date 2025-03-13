#include <SDL3/SDL_render.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <string>

#include "pong.hpp"
#include "utils.hpp"
#include "player.hpp"

Pong::Pong()
:window(NULL), renderer(NULL) 
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        Utils::LogSDLError("Failed to initialize: ");
    }

    window = SDL_CreateWindow("SDL3 Ping Pong", 800, 600, SDL_WINDOW_RESIZABLE);

    if (window == NULL)
    {
        Utils::LogSDLError("Failed to make window: ");
    }

    renderer = SDL_CreateRenderer(window, NULL);
    
    if (renderer == NULL)
    {
        Utils::LogSDLError("Failed to make renderer: ");
    }

    if (!SDL_SetRenderVSync(renderer, 1))
    {
        Utils::LogSDLError("SDL Vsync error:  ");
    }
}

Pong::~Pong()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void Pong::execute()
{
    SDL_Event event;
    gameOver = false;

    // game loop
    while (!gameOver)
    {
        // input handling
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                SDL_Log("SDL event quit");
                gameOver = true;
                break;
            
            default:
                break;
            }
        }

        // rendering
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);

        Player player;
        
        player.render(renderer);

        SDL_RenderPresent(renderer);
    }
}
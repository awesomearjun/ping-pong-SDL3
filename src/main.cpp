#include "SDL3/SDL_video.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Log("Error initializing: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SDL3 Ping Pong", 800, 600, SDL_WINDOW_RESIZABLE);

    if (window == NULL)
    {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return 2;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!SDL_SetRenderVSync(renderer, 1))
    {
        SDL_Log("SDL Renderer Vsync error: %s", SDL_GetError());
    }
    
    
    if (renderer == NULL)
    {
        SDL_Log("Create Renderer Error: %s", SDL_GetError());
        return 3;
    }

    SDL_Event event;
    bool gameOver = false;

    while (!gameOver)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                SDL_Log("SDL3 event quit");
                gameOver = true;
                break;
            
            default:
                break;
            }
        }
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
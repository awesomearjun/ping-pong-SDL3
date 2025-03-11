#pragma once

#include <SDL3/SDL.h>
#include <string>

class Pong
{
public:
    Pong();
    ~Pong();

    void execute();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::string error;
    bool gameOver;
};
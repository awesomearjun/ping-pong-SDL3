#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <string>

class Pong
{
public:
    Pong();
    ~Pong();

    void execute();
    void render();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::string error;
    bool gameOver;
};
#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <string>

#include "player.hpp"

class Pong
{
  public:
    Pong();
    ~Pong();

    void execute();
    void objectsSetup();
    void renderObjects();
    void handleInputs();

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    Player m_player;
    Player m_bot;

    bool m_gameOver;
    int m_screenWidth, m_screenHeight;
};
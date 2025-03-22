#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include "ball.hpp"
#include "player.hpp"

class Pong
{
  public:
    Pong();
    ~Pong();

    void execute();

  private:
    void objectsSetup();
    void renderObjects();
    void handleInputs();
    void clampPosition(Player &p_player);

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    Player m_player;
    Player m_bot;
    Ball m_ball;

    bool m_gameOver;
    int m_screenWidth, m_screenHeight;
};
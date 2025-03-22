#pragma once

#include "vector.hpp"

#include <SDL3/SDL_render.h>

class Player
{
  public:
    Player();
    ~Player() = default;

    void render(SDL_Renderer *p_renderer);

    Vector2f position;
    Vector2f size;
};

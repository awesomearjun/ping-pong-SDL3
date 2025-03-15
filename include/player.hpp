#pragma once

#include "entity.hpp"

#include <SDL3/SDL_render.h>

class Player : public Entity
{
  public:
    Player() = default;
    ~Player() = default;

    void render(SDL_Renderer *p_renderer);

  private:
    /* data */
};

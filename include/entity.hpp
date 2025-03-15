#pragma once

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include "vector.hpp"

class Entity
{
  public:
    Entity();
    ~Entity() = default;

    Vector2f position;
    Vector2f size;

  protected:
    void renderRect(SDL_Renderer *p_renderer, SDL_Rect *p_sprite);
};
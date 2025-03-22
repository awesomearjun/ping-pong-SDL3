#pragma once

#include "vector.hpp"

#include "SDL3/SDL_render.h"

class Ball
{
  public:
    Ball() = default;
    ~Ball() = default;

    void render(SDL_Renderer *p_renderer);

    Vector2f position;
    Vector2f size;

  private:
    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
};
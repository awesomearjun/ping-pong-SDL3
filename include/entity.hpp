#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

#include "vector.hpp"

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;


    Vector2f getPosition();
protected:
    void renderRect(SDL_Renderer *p_renderer, SDL_Rect *p_sprite);

    Vector2f position;
};
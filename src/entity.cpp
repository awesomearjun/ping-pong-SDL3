#include "entity.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include "utils.hpp"

Entity::Entity()
{
    position.x = 0;
    position.y = 0;

    size.x = 0;
    size.y = 0;
}

void Entity::renderRect(SDL_Renderer *p_renderer, SDL_Rect *p_sprite)
{
    if (p_sprite == nullptr)
    {
        Utils::LogError("P_Sprite is NULL!");
    }

    SDL_FRect renderedRect;
    renderedRect.x = static_cast<float>(p_sprite->x);
    renderedRect.y = static_cast<float>(p_sprite->y);
    renderedRect.w = static_cast<float>(p_sprite->w);
    renderedRect.h = static_cast<float>(p_sprite->h);

    SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(p_renderer, &renderedRect);
}

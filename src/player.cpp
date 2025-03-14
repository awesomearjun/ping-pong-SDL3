#include "player.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

void Player::render(SDL_Renderer *p_renderer)
{
    SDL_Rect sprite;
    sprite.x = position.x;
    sprite.y = position.y;
    sprite.w = size.x;
    sprite.h = size.y;

    renderRect(p_renderer, &sprite);
}
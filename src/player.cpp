#include "player.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include "entity.hpp"

void Player::render(SDL_Renderer *p_renderer)
{
    SDL_Rect sprite;
    sprite.x = position.x;
    sprite.y = position.y;
    sprite.w = 100;
    sprite.h = 100;

    renderRect(p_renderer, &sprite);
}
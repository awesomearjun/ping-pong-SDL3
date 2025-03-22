#include "player.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

Player::Player()
{
    position.x = 0;
    position.y = 0;
    size.x = 0;
    size.y = 0;
}

void Player::render(SDL_Renderer *p_renderer)
{
    SDL_FRect renderedRect;
    renderedRect.x = position.x;
    renderedRect.y = position.y;
    renderedRect.w = size.x;
    renderedRect.h = size.y;

    SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(p_renderer, &renderedRect);
}
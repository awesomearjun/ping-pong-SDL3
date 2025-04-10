#include "ball.hpp"

#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <unistd.h>

#include "utils.hpp"
#include "vector.hpp"

Ball::Ball()
    : ballVelocity(0.1, 0.2) {}

void Ball::update(float p_deltaTime)
{
    position += ballVelocity * p_deltaTime;
}

void Ball::render(SDL_Renderer *p_renderer)
{
    char tmp[256];
    getcwd(tmp, 256);

    std::string path = "";
    path += tmp;
    path += "/../res/gfx/img.jpg";

    SDL_Surface *surface = IMG_Load(path.c_str());

    if (surface)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(p_renderer, surface);

        if (texture == NULL)
            Utils::LogError("Texture at " + path + " is null");

        surface->w = size.x;
        surface->h = size.y;

        SDL_FRect destination;
        destination.x = position.x;
        destination.y = position.y;
        destination.w = size.x;
        destination.h = size.y;

        SDL_RenderTexture(p_renderer, texture, NULL, &destination);
    }
    else
    {
        Utils::LogSDLError("Surface is null");
    }
}
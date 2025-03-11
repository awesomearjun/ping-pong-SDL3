#include <SDL3/SDL_error.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#include "pong.hpp"

int main(int argc, char *argv[])
{
    Pong pong;
    pong.execute();
}
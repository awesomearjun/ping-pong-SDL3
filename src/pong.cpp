#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_render.h>
#include <string>

#include "player.hpp"
#include "pong.hpp"
#include "utils.hpp"

Pong::Pong() : m_window(NULL), m_renderer(NULL)
{
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    Utils::LogSDLError("Failed to initialize: ");
  }

  m_window = SDL_CreateWindow("SDL3 Ping Pong", 800, 600, SDL_WINDOW_RESIZABLE);

  if (m_window == NULL) {
    Utils::LogSDLError("Failed to make window: ");
  }

  m_renderer = SDL_CreateRenderer(m_window, NULL);

  if (m_renderer == NULL) {
    Utils::LogSDLError("Failed to make renderer: ");
  }

  if (!SDL_SetRenderVSync(m_renderer, 1)) {
    Utils::LogSDLError("SDL Vsync error:  ");
  }
}

Pong::~Pong()
{
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);

  SDL_Quit();
}

void Pong::execute()
{
  SDL_Event event;
  gameOver = false;

  while (!gameOver) {
    handleInputs();
    renderObjects();
  }
}

void Pong::renderObjects()
{
  SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(m_renderer);

  m_player.render(m_renderer);

  SDL_RenderPresent(m_renderer);
}

void Pong::handleInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                SDL_Log("SDL event quit");
                gameOver = true;
                break;

            default:
                break;
        }
    }

    const bool *currentKeySates = SDL_GetKeyboardState(NULL);
    int8_t playerDirection = 0;
    Vector2f playerVelocity(0, 10);

    if (currentKeySates[SDL_SCANCODE_W])
    {
        playerDirection = -1;
    }
    if (currentKeySates[SDL_SCANCODE_S])
    {
        playerDirection = 1;
    }

    // TODO: Add deltatime
    m_player.position += playerVelocity * playerDirection;
}

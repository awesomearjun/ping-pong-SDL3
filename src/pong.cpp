#include "pong.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <string>

#include "ball.hpp"
#include "player.hpp"
#include "utils.hpp"

Pong::Pong() : m_window(NULL), m_renderer(NULL)
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        Utils::LogSDLError("Failed to initialize: ");
    }

    m_window = SDL_CreateWindow("SDL3 Ping Pong", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_SetWindowMinimumSize(m_window, 729, 484);

    if (m_window == NULL)
    {
        Utils::LogSDLError("Failed to make window: ");
    }

    m_renderer = SDL_CreateRenderer(m_window, NULL);

    if (m_renderer == NULL)
    {
        Utils::LogSDLError("Failed to make renderer: ");
    }

    if (!SDL_SetRenderVSync(m_renderer, 1))
    {
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
    objectsSetup();

    m_gameOver = false;

    while (!m_gameOver)
    {
        float buffer1 = SDL_GetTicks();

        handleInputs();
        renderObjects();

        float buffer2 = SDL_GetTicks();
        deltaTime = buffer2 - buffer1;
    }
}

void Pong::handleInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            SDL_Log("SDL event quit");
            m_gameOver = true;
            break;
        case SDL_EVENT_WINDOW_RESIZED:
            SDL_GetWindowSizeInPixels(m_window, &m_screenWidth, &m_screenHeight);
            objectsSetup();
            break;

        default:
            break;
        }
    }

    const bool *currentKeySates = SDL_GetKeyboardState(NULL);

    m_player.update(deltaTime, currentKeySates);

    clampPosition(m_player);
    clampPosition(m_bot);
}

void Pong::renderObjects()
{
    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(m_renderer);

    m_player.render(m_renderer);
    m_bot.render(m_renderer);
    m_ball.render(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void Pong::objectsSetup()
{
    SDL_GetWindowSizeInPixels(m_window, &m_screenWidth, &m_screenHeight);

    float screenHeightFloat = static_cast<float>(m_screenHeight);
    float screenWidthFloat = static_cast<float>(m_screenWidth);

    // Set sizes
    m_player.size.x = 30 * (screenWidthFloat / 700);
    m_player.size.y = (50 * screenHeightFloat) / 200;
    m_bot.size.x = 30 * (screenWidthFloat / 700);
    m_bot.size.y = (50 * screenHeightFloat) / 200;

    // Same so that the image stays a square
    m_ball.size.x = screenWidthFloat / 20;
    m_ball.size.y = screenWidthFloat / 20;

    // Set initial positions
    m_player.position.x = 0;
    m_bot.position.x = m_screenWidth - m_bot.size.x;
    m_ball.position.x = (screenWidthFloat / 2) - (m_ball.size.y / 2);

    // Render in middle
    m_player.position.y = (screenHeightFloat / 2) - (m_player.size.y / 2);
    m_bot.position.y = (screenHeightFloat / 2) - (m_bot.size.y / 2);
    m_ball.position.y = (screenHeightFloat / 2) - (m_ball.size.y / 2);
}

void Pong::clampPosition(Player &p_player)
{
    uint32_t relativeHeight = m_screenHeight - p_player.size.y;

    if (p_player.position.y <= 0)
    {
        p_player.position.y = 0;
    }
    if (p_player.position.y > relativeHeight)
    {
        p_player.position.y = relativeHeight;
    }
}

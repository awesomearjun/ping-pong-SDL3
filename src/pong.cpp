#include "pong.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <ostream>
#include <string>

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_video.h"
#include "player.hpp"
#include "utils.hpp"
#include <iostream>

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
        handleInputs();
        renderObjects();
    }
}

void Pong::objectsSetup()
{
    SDL_GetWindowSizeInPixels(m_window, &m_screenWidth, &m_screenHeight);

    // Set sizes
    m_player.size.x = 30 * (m_screenWidth / 700);
    m_player.size.y = (50 * m_screenHeight) / 200;
    m_bot.size.x = 30 * (m_screenWidth / 700);
    m_bot.size.y = (50 * m_screenHeight) / 200;

    // Set initial positions
    m_player.position.x = 0;
    m_bot.position.x = m_screenWidth - m_bot.size.x;

    // Render in middle
    m_player.position.y = (m_screenHeight / 2) - (m_player.size.y / 2);
    m_bot.position.y = (m_screenHeight / 2) - (m_bot.size.y / 2);

    m_bot.position.print();
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
    int8_t playerDirection = 0;
    static Vector2f playerVelocity(0, 10);

    // Player Movement
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
    m_player.position.print();

    clampPositions();
}

void Pong::clampPositions()
{
    // Remove if don't want to add special stuffs
    // Player size == bot size
    uint32_t relativeHeightPlayer = m_screenHeight - m_player.size.y;
    uint32_t relativeHeightBot = m_screenHeight - m_bot.size.y;

    if (m_player.position.y <= 0)
    {
        std::cout << m_player.position.y << std::endl;
        m_player.position.y = 0;
    }
    if (m_player.position.y > relativeHeightPlayer)
    {
        std::cout << relativeHeightPlayer << ", " << m_player.size.y << std::endl;
        m_player.position.y = relativeHeightPlayer;
    }
    if (m_bot.position.y > 0)
    {
        m_bot.position.y = 0;
    }
    if (m_bot.position.y > relativeHeightBot)
    {
        m_bot.position.y = relativeHeightBot;
    }
}

void Pong::renderObjects()
{
    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(m_renderer);

    m_player.render(m_renderer);
    m_bot.render(m_renderer);

    SDL_RenderPresent(m_renderer);
}

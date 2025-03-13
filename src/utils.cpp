#include "utils.hpp"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_error.h>
#include <stdexcept>
#include <string>

void Utils::LogSDLError(std::string stringToLog)
{
    std::string error = stringToLog;
    error += SDL_GetError();

    SDL_Log("%s", error.c_str());
    throw std::runtime_error(error);
}

void Utils::LogError(std::string stringToLog)
{
    throw std::runtime_error(stringToLog);
}
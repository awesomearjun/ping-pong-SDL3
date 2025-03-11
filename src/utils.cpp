#include <SDL3/SDL_log.h>
#include <SDL3/SDL_error.h>
#include <stdexcept>

#include "utils.hpp"

void Utils::LogSDLError(std::string stringToLog)
{
    std::string error = stringToLog;
    error += SDL_GetError();

    SDL_Log("%s", error.c_str());
    throw std::runtime_error(error);
}
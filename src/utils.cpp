#include "utils.hpp"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_log.h>
#include <stdexcept>
#include <string>

void Utils::LogSDLError(std::string p_stringToLog)
{
    std::string error = "\n[ERROR] ";
    error += p_stringToLog;
    error += ": ";
    error += SDL_GetError();
    error += "\n";

    SDL_Log("%s", error.c_str());
    throw std::runtime_error(error);
}

void Utils::LogError(std::string p_stringToLog)
{
    std::string error = "\n[ERROR] ";
    error += p_stringToLog;
    error += "\n";
    throw std::runtime_error(error);
}
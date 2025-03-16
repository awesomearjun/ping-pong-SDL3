#!/bin/bash
# Working on it, not done yet!
cd ../
mkdir vendor
cd vendor
echo "set(SDL_TEST OFF)

add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE SDL3::SDL3 SDL3_image::SDL3_image)" > CMakeLists.txt
git submodule add https://github.com/libsdl-org/SDL.git
cd SDL
git checkout 3b9f0dff1023dfde49e645e318cf7cfb7b83c7ba
cd ../
git submodule add https://github.com/libsdl-org/SDL_image.git
cd SDL_image
git checkout d4153324124963b8003e4e5b1d6743661969fdf5
cd ../../
echo "All done 👍"
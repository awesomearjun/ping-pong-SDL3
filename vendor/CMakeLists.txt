set(SDL_TEST OFF)

add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE SDL3::SDL3 SDL3_image::SDL3_image)
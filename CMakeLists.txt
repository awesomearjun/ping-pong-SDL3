cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 11)

project(SDL3_PingPong)

add_subdirectory(src)
add_subdirectory(vendor)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
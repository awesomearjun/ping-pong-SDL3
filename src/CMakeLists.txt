set(SRCS
    main.cpp
    pong.cpp
    utils.cpp
    entity.cpp
    vector.cpp
    player.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
set(PROJECT_PATH "${CMAKE_SOURCE_DIR}/include")
message(CMAKE_SOURCE_DIR="${PROJECT_PATH}")
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
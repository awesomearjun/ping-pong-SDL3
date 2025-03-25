set(SRCS
    main.cpp
    pong.cpp
    utils.cpp
    vector.cpp
    player.cpp
    ball.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

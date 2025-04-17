cmake_minimum_required(VERSION 3.10)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(snake 
    main.cpp
    utils/moveRect.cpp
    utils/collision.cpp
)
target_link_libraries(snake ${SDL2_LIBRARIES})

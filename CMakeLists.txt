cmake_minimum_required(VERSION 3.23.0)
project(pong VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(pong main.cpp sdl_functions.cpp sdl_functions.hpp class.hpp)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_link_libraries(pong PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_ttf::SDL2_ttf)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

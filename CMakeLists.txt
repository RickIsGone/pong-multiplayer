cmake_minimum_required(VERSION 3.28.0)
project(pong VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(pong main.cpp)

find_package(asio CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

target_link_libraries(pong PRIVATE asio::asio SDL2::SDL2 SDL2::SDL2main SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

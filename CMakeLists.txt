cmake_minimum_required(VERSION 3.10)

project(
    rockpaperscissors
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)
add_subdirectory(bin)
cmake_minimum_required(VERSION 3.6)
project(Tetris)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Game.h Block.cpp Block.h Structure.cpp Structure.h cCoord.h cCoord.cpp)
add_executable(Tetris ${SOURCE_FILES})
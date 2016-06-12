cmake_minimum_required(VERSION 2.8.9)
project(tictactoe)

include_directories(include)

#file(GLOB SOURCES "src/*.cpp")

#add_executable(tictactoe ${SOURCES})
add_executable(tictactoe src/main.cpp src/Player.cpp src/GameBoard.cpp src/BoardField.cpp)

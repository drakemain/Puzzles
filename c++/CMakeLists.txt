cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")

project(puzzles)

add_executable(../out/binary-tree ../src/binary-tree.cc)
add_executable(../out/linked-list ../src/linked-list.cc)
add_executable(../out/vector ../src/vector.cc)
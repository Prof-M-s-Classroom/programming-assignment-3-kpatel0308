cmake_minimum_required(VERSION 3.24)
project(PA3)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(PA3 main.cpp graph.cpp heap.cpp)

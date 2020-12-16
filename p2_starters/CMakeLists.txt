cmake_minimum_required(VERSION 2.7)
project(p2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(p2 p2.cpp simulation.cpp)



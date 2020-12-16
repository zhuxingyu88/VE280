cmake_minimum_required(VERSION 2.7)
project(p1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(p1 p1.cpp)



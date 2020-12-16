cmake_minimum_required(VERSION 2.7)
project(mid)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(ex1 ex1.cpp)
add_executable(ex2 ex2.cpp)
add_executable(ex3 ex3.cpp)
add_executable(ex4 ex4.cpp)


cmake_minimum_required(VERSION 2.7)
project(mid)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(ex1 re.cpp)
add_executable(ex2 selectMod.cpp recursive.cpp recursive.h)
add_executable(ex3 testLongestCommon.cpp)
add_executable(ex4 ex4.cpp)


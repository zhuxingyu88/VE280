cmake_minimum_required(VERSION 2.7)
project(final)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(ex1 ex1.cpp)
add_executable(tree binaryTree.cpp binaryTree.h)
add_executable(dic dict.h dict.hpp)


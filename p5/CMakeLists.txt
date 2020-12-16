cmake_minimum_required(VERSION 2.7)
project(p5)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(dlist test.cpp dlist.h dlist_impl.h)
add_executable(rpn dlist.h dlist_impl.h rpn.cpp)
add_executable(cache cache.cpp dlist.h dlist_impl.h)
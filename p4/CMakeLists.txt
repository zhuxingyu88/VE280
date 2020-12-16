cmake_minimum_required(VERSION 2.7)
project(p4)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(decompress binaryTree.cpp binaryTree.h decompress.cpp huffmanTree.cpp huffmanTree.h)
add_executable(compress binaryTree.cpp binaryTree.h compress.cpp huffmanTree.cpp huffmanTree.h)
add_executable(testcase1 binaryTree.h binaryTree.cpp test1.cpp)
add_executable(testcase2 binaryTree.h binaryTree.cpp testcase2.cpp)

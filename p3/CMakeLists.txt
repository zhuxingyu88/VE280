cmake_minimum_required(VERSION 2.7)
project(p3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

add_executable(p3 card.cpp card.h hand.h player.h rand.cpp rand.h deck.cpp hand.cpp player.cpp blackjack.cpp)
add_executable(decktest example.cpp deck.cpp deck.h card.h card.cpp)
add_executable(handtest handtest.cpp hand.cpp hand.h card.h card.cpp)


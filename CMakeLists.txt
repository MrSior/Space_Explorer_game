cmake_minimum_required(VERSION 3.19)
project(Space_Explorer_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Space_Explorer_game main.cpp)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Space_Explorer_game sfml-graphics sfml-audio)
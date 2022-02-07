cmake_minimum_required(VERSION 3.19)
project(Space_Explorer_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Space_Explorer_game main.cpp Game/GameModel.cpp Game/GameModel.h Game/GameRender.cpp Game/GameRender.h Game/GameController.cpp Game/GameController.h Game/Scene/Scene.cpp Game/Scene/Scene.h Game/Scene/Player/Player.cpp Game/Scene/Player/Player.h Game/Scene/Bullet/Bullet.cpp Game/Scene/Bullet/Bullet.h Game/Scene/Enemy/Enemy.cpp Game/Scene/Enemy/Enemy.h)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Space_Explorer_game sfml-graphics sfml-audio)
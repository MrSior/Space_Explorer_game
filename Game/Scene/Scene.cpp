//
// Created by Семён Чубенко on 02.02.2022.
//

#include "Scene.h"

Scene::Scene() {
    Init();
}

void Scene::Init() {

}

void Scene::Move_Player(sf::Vector2<float> direction) {
    player.Move(direction);
}

sf::Vector2<float> Scene::Get_player_position() {
    return player.Get_position();
}

void Scene::Update() {
    player.Update();
}

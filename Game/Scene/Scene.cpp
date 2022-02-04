//
// Created by Семён Чубенко on 02.02.2022.
//

#include "Scene.h"
#include "iostream"

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
    for (int i = 0; i < bullets.size(); ++i) {
        if (bullets[i]->Get_time().asSeconds() > bullets[i]->Get_life_time()){
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
            --i;
        }
        bullets[i]->Update();
    }
}

void Scene::Create_bullet() {
    //Bullet bullet(player.Get_position(), player.Get_looking_direction(), player.Get_angle());
    Bullet* bullet = new Bullet(player.Get_position(), player.Get_looking_direction(), player.Get_angle());

    bullets.push_back(bullet);
}

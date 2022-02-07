//
// Created by Семён Чубенко on 02.02.2022.
//

#include "Scene.h"
#include "iostream"
#include "cmath"

Scene::Scene() {
    Init();
}

void Scene::Init() {
    gen.seed(time(0));
    is_player_dead = false;
}

void Scene::Move_Player(sf::Vector2<float> direction) {
    player.Move(direction);
}

sf::Vector2<float> Scene::Get_player_position() {
    return player.Get_position();
}

void Scene::Update() {
    player.Update();
    if (enemies.size() == 0){
        sf::Vector2f spawn_position;
        spawn_position = sf::Vector2f(-10, -10);
        Create_Enemy(spawn_position);
        spawn_position = sf::Vector2f(sf::VideoMode::getDesktopMode().width + 10, -10);
        Create_Enemy(spawn_position);
        spawn_position = sf::Vector2f(sf::VideoMode::getDesktopMode().width + 10 ,
                                      sf::VideoMode::getDesktopMode().height + 10);
        Create_Enemy(spawn_position);
        spawn_position = sf::Vector2f(-10, sf::VideoMode::getDesktopMode().height + 10);
        Create_Enemy(spawn_position);
    }
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i]->Update(player.Get_position());
        if (enemies[i]->Is_in_attack_distance(player.Get_position()) && enemies[i]->Can_enemy_shoot()){
            Create_enemy_bullet(enemies[i]);
        }
    }

    for (int i = 0; i < enemy_bullets.size() && i >= 0; ++i) {
        if (enemy_bullets[i]->Get_time().asSeconds() > enemy_bullets[i]->Get_life_time()){
            Bullet* address = enemy_bullets[i];
            delete address;
            enemy_bullets.erase(enemy_bullets.begin() + i);
        } else {
            enemy_bullets[i]->Update();
        }
    }

    for (int i = 0; i < bullets.size() && i >= 0; ++i) {
        if (bullets[i]->Get_time().asSeconds() > bullets[i]->Get_life_time()){
            Bullet* address = bullets[i];
            delete address;
            bullets.erase(bullets.begin() + i);
        } else {
            bullets[i]->Update();
        }
    }

    for (int i = 0; i < bullets.size(); ++i) {
        for (int j = 0; j < enemies.size(); ++j) {
            auto bullet_pos = bullets[i]->Get_position();
            auto enemy_pos = enemies[j]->Get_position();
            auto between = bullet_pos - enemy_pos;
            float length = std::sqrt(between.x * between.x + between.y * between.y);
            if (length < 25){
                delete enemies[j];
                delete bullets[i];
                bullets.erase(bullets.begin() + i);
                enemies.erase(enemies.begin() + j);
            }
        }
    }

    for (int i = 0; i < enemy_bullets.size(); ++i) {
        auto bullet_pos = enemy_bullets[i]->Get_position();
        auto between = bullet_pos - player.Get_position();
        float length = std::sqrt(between.x * between.x + between.y * between.y);
        if (length < 25){
            player.Get_damage(1);
            delete enemy_bullets[i];
            enemy_bullets.erase(enemy_bullets.begin() + i);
        }
    }
    if (player.Get_hp() < 0){
        is_player_dead = true;
    }
}

void Scene::Create_bullet() {
    //Bullet bullet(player.Get_position(), player.Get_looking_direction(), player.Get_angle());
    Bullet* bullet = new Bullet(player.Get_position(), player.Get_looking_direction(), player.Get_angle(), false);

    bullets.push_back(bullet);
}

void Scene::Create_Enemy(sf::Vector2f spawn_position) {
    std::uniform_int_distribution<> dis(4, 8);
    Enemy* enemy = new Enemy(spawn_position, 100 * dis(gen));
    enemies.push_back(enemy);
}

void Scene::Create_enemy_bullet(Enemy *enemy) {
    Bullet* bullet = new Bullet(enemy->Get_position(), enemy->Get_looking_direction(), enemy->Get_angle(), true);
    enemy_bullets.push_back(bullet);
}

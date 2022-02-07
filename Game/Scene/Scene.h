//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_SCENE_H
#define SPACE_EXPLORER_GAME_SCENE_H

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Enemy/Enemy.h"
#include "vector"

class Scene {
public:
    Player player;
    std::vector<Bullet*> bullets;
    std::vector<Bullet*> enemy_bullets;
    std::vector<Enemy*> enemies;
    std::mt19937 gen;
    bool is_player_dead;

    Scene();
    void Init();
    void Move_Player(sf::Vector2<float> direction);
    sf::Vector2<float> Get_player_position();
    void Create_bullet();
    void Create_Enemy(sf::Vector2f spawn_position);
    void Create_enemy_bullet(Enemy* enemy);

    void Update();
};


#endif //SPACE_EXPLORER_GAME_SCENE_H

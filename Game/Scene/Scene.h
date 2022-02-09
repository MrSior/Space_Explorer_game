//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_SCENE_H
#define SPACE_EXPLORER_GAME_SCENE_H

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Enemy/Enemy.h"
#include "ExplosionAnimation/Animation.h"
#include "vector"

class Scene {
public:
    Player player;
    std::vector<Bullet*> bullets;
    std::vector<Bullet*> enemy_bullets;
    std::vector<Enemy*> enemies;
    std::vector<Animation*> explosion_animations;
    std::vector<sf::Texture> explosion_frames;
    std::mt19937 gen;
    bool is_player_dead;
    sf::Clock spawn_timer;
    float spawn_time;
    int max_enemy_hp;
    int score;

    Scene();
    void Init();
    void Move_Player(sf::Vector2<float> direction);
    sf::Vector2<float> Get_player_position();
    void Create_bullet();
    void Create_Enemy(sf::Vector2f spawn_position);
    void Create_enemy_bullet(Enemy* enemy);
    void Create_explosion_animation(sf::Vector2f position);

    void Update();
};


#endif //SPACE_EXPLORER_GAME_SCENE_H

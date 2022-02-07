//
// Created by Семён Чубенко on 04.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_BULLET_H
#define SPACE_EXPLORER_GAME_BULLET_H

#include "SFML/Graphics.hpp"

class Bullet {
private:
    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture enemy_bullet_texture;
    float move_speed;
    float angle;
    sf::Clock clock;
    float life_time;
    bool is_enemy_bullet;
public:
    Bullet(sf::Vector2f _position, sf::Vector2f _direction, float _angle, bool _is_enemy_bullet);

    sf::Sprite Get_sprite();
    sf::Time Get_time();
    float Get_life_time();
    sf::Vector2f Get_position();

    void Init();
    void Update();
    void Move();
};


#endif //SPACE_EXPLORER_GAME_BULLET_H

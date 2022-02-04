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
    float move_speed;
    float angle;
    sf::Clock clock;
    float life_time;
public:
    Bullet(sf::Vector2f _position, sf::Vector2f _direction, float _angle);

    sf::Sprite Get_sprite();
    sf::Time Get_time();
    float Get_life_time();

    void Init();
    void Update();
    void Move();
};


#endif //SPACE_EXPLORER_GAME_BULLET_H

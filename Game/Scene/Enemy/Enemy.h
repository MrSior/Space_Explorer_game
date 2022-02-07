//
// Created by Семён Чубенко on 06.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_ENEMY_H
#define SPACE_EXPLORER_GAME_ENEMY_H

#include "SFML/Graphics.hpp"
#include "random"

class Enemy {
private:
    sf::Vector2<float> position;
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    float move_speed;
    float _angle;
    float attack_distance;
    sf::Vector2f looking_direction;
    sf::Clock last_shoot;
    float shoot_time;
    int circle_move_direction;
    float circle_move_speed;
public:
    Enemy(sf::Vector2f spawn_position, int _attack_distance, int _circle_move_direction, float _circle_move_speed);
    void Init();
    void Move(sf::Vector2<float> movement);
    sf::Vector2<float> Get_position();
    sf::Sprite Get_sprite();
    sf::Vector2f Get_looking_direction();
    void Look_at(sf::Vector2f target);
    float Get_angle();
    bool Is_in_attack_distance(sf::Vector2f player_pos);
    bool Can_enemy_shoot();

    void Update(sf::Vector2f player_pos);
};


#endif //SPACE_EXPLORER_GAME_ENEMY_H

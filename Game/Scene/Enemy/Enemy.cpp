//
// Created by Семён Чубенко on 06.02.2022.
//

#include "Enemy.h"
#include "cmath"
#include "random"
#include "ctime"
#include "iostream"

Enemy::Enemy(sf::Vector2f spawn_position, int _attack_distance, int _circle_move_direction, float _circle_move_speed) {
    position = spawn_position;
    sprite.setPosition(spawn_position);
    attack_distance = _attack_distance;
    circle_move_speed = _circle_move_speed;
    circle_move_direction = _circle_move_direction;
    Init();
}

void Enemy::Init() {
    move_speed = 1.f;
    looking_direction = sf::Vector2f (0, -1);
    texture.loadFromFile("./Images/enemy_png.png");
    sprite.setTexture(texture);
    sprite.scale(5, 5);
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2,
                     sprite.getTexture()->getSize().y / 2);
    last_shoot.restart();
    shoot_time = 0.7;
}

void Enemy::Move(sf::Vector2f movement) {
    sprite.move(move_speed * movement);
    position += movement * move_speed;
}

sf::Vector2<float> Enemy::Get_position() {
    return sprite.getPosition();
}

sf::Sprite Enemy::Get_sprite() {
    return sprite;
}

sf::Vector2f Enemy::Get_looking_direction() {
    return looking_direction;
}

void Enemy::Look_at(sf::Vector2f target) {
    auto direction = sf::Vector2f (target.x - position.x, target.y - position.y);
    looking_direction = direction;
    sf::Vector2f up(0, -1);
    float length_a = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float length_b = 1;
    float angle = acos(float (direction.x * up.x + direction.y * up.y) / (length_a * length_b)) * 180 / 3.141592;
    if (target.x < position.x){
        angle = -angle;
    }
    _angle = angle;
    sprite.setRotation(angle);
}

float Enemy::Get_angle() {
    return _angle;
}

void Enemy::Update(sf::Vector2f player_pos) {
    sf::Vector2f direction = player_pos - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > float (attack_distance)) {
        direction.x = direction.x / length;
        direction.y = direction.y / length;
        Move(direction);
    } else {
        direction.x = direction.x / length;
        direction.y = direction.y / length;
        _angle += 0.1 * circle_move_speed;
        double angle = _angle - 180;
        if (angle < 0){
            angle = std::abs(angle);
        } else {
            angle = 180 + (180 - angle);
        }
        angle = angle * 3.1415926 / 180;
        sf::Vector2f dote(player_pos.x, player_pos.y - length);
        double new_x = player_pos.x + cos(angle) * (dote.x - player_pos.x) - sin(angle) * (-dote.y + player_pos.y);
        double new_y = -player_pos.y + sin(angle) * (dote.x - player_pos.x) + cos(angle) * (-dote.y + player_pos.y);
        sf::Vector2f new_pos(new_x, -new_y);
        sf::Vector2f move (new_pos.x - position.x, new_pos.y - position.y);
        move.x = move.x * circle_move_direction;
        move.y = move.y * circle_move_direction;
        Move(move);
        Move(-direction);
    }
    Look_at(player_pos);
    //std::cout << _angle << '\n';
}

bool Enemy::Is_in_attack_distance(sf::Vector2f player_pos) {
    sf::Vector2f direction = player_pos - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    return length <= attack_distance;
}

bool Enemy::Can_enemy_shoot() {
    if (last_shoot.getElapsedTime().asSeconds() > shoot_time){
        last_shoot.restart();
        return true;
    }
    return false;
}

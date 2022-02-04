//
// Created by Семён Чубенко on 04.02.2022.
//

#include "Bullet.h"
#include "iostream"
#include "cmath"

Bullet::Bullet(sf::Vector2f _position, sf::Vector2f _direction, float _angle) {
    position = _position;
    direction = _direction;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction.x = direction.x / length;
    direction.y = direction.y / length;
    angle = _angle;
    Init();
}

void Bullet::Init() {
    move_speed = 3;
    life_time = 3;
    clock.restart();
    texture.loadFromFile("./Images/bullet_png.png");
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.1);
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2,
                     sprite.getTexture()->getSize().y / 2);
    sprite.setPosition(position);
    sprite.setRotation(angle);
}

void Bullet::Update() {
    Move();
}

void Bullet::Move() {
    position += direction * move_speed;
    sprite.move(direction * move_speed);
    //std::cout << position.x << " " << position.y << '\n';
}

sf::Sprite Bullet::Get_sprite() {
    return sprite;
}

sf::Time Bullet::Get_time() {
    return clock.getElapsedTime();
}

float Bullet::Get_life_time() {
    return life_time;
}

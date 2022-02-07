//
// Created by Семён Чубенко on 02.02.2022.
//

#include "Player.h"
#include "iostream"
#include "cmath"

Player::Player(sf::Vector2<float> start_pos) {
    //position = start_pos;
    shape.setPosition(start_pos);
    Init();
}

void Player::Move(sf::Vector2<float> movement) {
    if (movement.x == 1 && position.x == sf::VideoMode::getDesktopMode().width) {
        movement.x = 0;
    }
    if (movement.x == -1 && position.x == 0) {
        movement.x = 0;
    }
    if (movement.y == 1 && position.y == sf::VideoMode::getDesktopMode().height) {
        movement.y = 0;
    }
    if (movement.y == -1 && position.y == 0) {
        movement.y = 0;
    }
    sprite.move(move_speed * movement);
    position += movement * move_speed;
}

Player::Player() {
    position = sf::Vector2<float> (sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().width / 3);
    sprite.setPosition(position);
    Init();
}

void Player::Init() {
    move_speed = 1.f;
    hp = 10;
    looking_direction = sf::Vector2f (0, -1);
    texture.loadFromFile("./Images/SpaceShip_Player.png");
    sprite.setTexture(texture);
    sprite.scale(5, 5);
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2,
                     sprite.getTexture()->getSize().y / 2);
}

sf::Vector2<float> Player::Get_position() {
    return sprite.getPosition();
}

sf::Sprite Player::Get_sprite() {
    return sprite;
}

void Player::Update() {
    sf::Vector2<float> movement(0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movement.y = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movement.y = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x = -1;
    }
    Move(movement);

}

void Player::Look_at(sf::Vector2i target) {
    auto direction = sf::Vector2f (float (target.x) - position.x, float (target.y) - position.y);
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

sf::Vector2f Player::Get_looking_direction() {
    return looking_direction;
}

float Player::Get_angle() {
    return _angle;
}

void Player::Get_damage(int damage) {
    hp -= damage;
}

int Player::Get_hp() {
    return hp;
}

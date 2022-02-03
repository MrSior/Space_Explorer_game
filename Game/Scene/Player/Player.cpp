//
// Created by Семён Чубенко on 02.02.2022.
//

#include "Player.h"

Player::Player(sf::Vector2<float> start_pos) {
    //position = start_pos;
    shape.setPosition(start_pos);
    Init();
}

void Player::Move(sf::Vector2<float> movement) {
    if (movement.x == 1 && position.x == sf::VideoMode::getDesktopMode().width) {
        return;
    }
    if (movement.x == -1 && position.x == 0) {
        return;
    }
    if (movement.y == 1 && position.y == sf::VideoMode::getDesktopMode().height) {
        return;
    }
    if (movement.y == -1 && position.y == 0) {
        return;
    }
    sprite.move(move_speed * movement);
    position += movement * move_speed;
}

Player::Player() {
    position = sf::Vector2<float> (0, 0);
    shape.setPosition(0, 0);
    Init();
}

void Player::Init() {
    move_speed = 1.f;
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2<float> (50, 50));
    texture.loadFromFile("./Images/SpaceShip_Player.png");
    sprite.setTexture(texture);
    sprite.scale(5, 5);
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2,
                     sprite.getTexture()->getSize().y / 2);
}

sf::Vector2<float> Player::Get_position() {
    return position;
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

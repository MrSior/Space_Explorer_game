//
// Created by Семён Чубенко on 08.02.2022.
//

#include "ExplosionAnimation.h"

ExplosionAnimation::ExplosionAnimation(sf::Vector2f position) {
    this->position = position;
    Init();
}

void ExplosionAnimation::Init() {
    frame_change_time = 0.1;
    sf::Texture texture;
    for (int i = 0; i < 12; ++i) {
        texture.loadFromFile("./Images/Explosion/" + std::to_string(i + 1) + ".png");
        frames.push_back(texture);
    }
    is_finished = false;
    clock.restart();
    current_frame = 0;
    frame.setTexture(frames[0]);
    frame.setPosition(position);
}

void ExplosionAnimation::Update() {
    if (clock.getElapsedTime().asSeconds() > frame_change_time) {
        current_frame++;
        clock.restart();
    }
    if (current_frame >= frames.size()){
        is_finished = true;
    } else {
        frame.setTexture(frames[current_frame]);
        frame.setOrigin(frame.getTexture()->getSize().x / 2,
                         frame.getTexture()->getSize().y / 2);
        frame.setScale(0.5, 0.5);
    }
}

sf::Sprite ExplosionAnimation::Get_sprite() {
    return frame;
}

bool ExplosionAnimation::Get_is_finished() {
    return is_finished;
}

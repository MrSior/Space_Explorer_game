//
// Created by Семён Чубенко on 08.02.2022.
//

#include "Animation.h"

Animation::Animation(sf::Vector2f position) {
    this->position = position;
    Init();
}

void Animation::Init() {
    frame_change_time = 0.1;
//    sf::Texture texture;
//    for (int i = 0; i < 12; ++i) {
//        texture.loadFromFile("./Images/Explosion/" + std::to_string(i + 1) + ".png");
//        frames.push_back(texture);
//    }
    is_finished = false;
    clock.restart();
    current_frame = 0;
    frame.setTexture(frames[0]);
    frame.setPosition(position);
}

void Animation::Update() {
    if (clock.getElapsedTime().asSeconds() > frame_change_time) {
        current_frame++;
        clock.restart();
    }
    if (current_frame >= frames.size()){
        if (!is_looped) {
            is_finished = true;
        } else {
            current_frame = 0;
        }
    } else {
        frame.setTexture(frames[current_frame]);
        frame.setOrigin(frame.getTexture()->getSize().x / 2,
                         frame.getTexture()->getSize().y / 2);
        frame.setScale(0.5, 0.5);
    }
}

sf::Sprite Animation::Get_sprite() {
    return frame;
}

bool Animation::Get_is_finished() {
    return is_finished;
}

Animation::Animation(sf::Vector2f position, std::vector<sf::Texture> frames, bool is_looped) {
    this->position = position;
    this->frames = frames;
    this->is_looped = is_looped;
    Init();
}

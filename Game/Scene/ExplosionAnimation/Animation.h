//
// Created by Семён Чубенко on 08.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_ANIMATION_H
#define SPACE_EXPLORER_GAME_ANIMATION_H

#include "SFML/Graphics.hpp"

class Animation {
private:
    std::vector<sf::Texture> frames;
    float frame_change_time;
    bool is_finished;
    sf::Vector2f position;
    sf::Clock clock;
    int current_frame;
    sf::Sprite frame;
    bool is_looped;
public:
    Animation(sf::Vector2f position);
    Animation(sf::Vector2f position, std::vector<sf::Texture> frames, bool is_looped);

    void Init();
    void Update();
    sf::Sprite Get_sprite();
    bool Get_is_finished();
};


#endif //SPACE_EXPLORER_GAME_ANIMATION_H

//
// Created by Семён Чубенко on 08.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_EXPLOSIONANIMATION_H
#define SPACE_EXPLORER_GAME_EXPLOSIONANIMATION_H

#include "SFML/Graphics.hpp"

class ExplosionAnimation {
private:
    std::vector<sf::Texture> frames;
    float frame_change_time;
    bool is_finished;
    sf::Vector2f position;
    sf::Clock clock;
    int current_frame;
    sf::Sprite frame;
public:
    ExplosionAnimation(sf::Vector2f position);

    void Init();
    void Update();
    sf::Sprite Get_sprite();
    bool Get_is_finished();
};


#endif //SPACE_EXPLORER_GAME_EXPLOSIONANIMATION_H

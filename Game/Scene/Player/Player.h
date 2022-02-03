//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_PLAYER_H
#define SPACE_EXPLORER_GAME_PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
private:
    sf::Vector2<float> position;
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    float move_speed;

public:
    Player();
    Player(sf::Vector2<float> start_pos);
    void Init();
    void Move(sf::Vector2<float> movement);
    sf::Vector2<float> Get_position();
    sf::Sprite Get_sprite();

    void Update();
};


#endif //SPACE_EXPLORER_GAME_PLAYER_H

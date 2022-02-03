//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_SCENE_H
#define SPACE_EXPLORER_GAME_SCENE_H

#include "Player/Player.h"

class Scene {
public:
    Player player;
    Scene();
    void Init();
    void Move_Player(sf::Vector2<float> direction);
    sf::Vector2<float> Get_player_position();

    void Update();
};


#endif //SPACE_EXPLORER_GAME_SCENE_H

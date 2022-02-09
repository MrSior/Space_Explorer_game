//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_GAMEMODEL_H
#define SPACE_EXPLORER_GAME_GAMEMODEL_H

#include "Scene/Scene.h"

class GameModel {
public:
    Scene* scene;
    bool is_menu_open;
    bool is_game_end;

    GameModel();
    void Move_Player(sf::Vector2<float> direction);
    sf::Vector2<float> Get_player_position();
};


#endif //SPACE_EXPLORER_GAME_GAMEMODEL_H

//
// Created by Семён Чубенко on 02.02.2022.
//

#include "GameModel.h"


GameModel::GameModel() {
    scene = new Scene();
    is_menu_open = true;
    is_game_end = true;
}

void GameModel::Move_Player(sf::Vector2<float> direction) {
    scene->Move_Player(direction);
}

sf::Vector2<float> GameModel::Get_player_position() {
    return scene->Get_player_position();
}

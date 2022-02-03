//
// Created by Семён Чубенко on 02.02.2022.
//

#include "GameModel.h"


GameModel::GameModel() {

}

void GameModel::Move_Player(sf::Vector2<float> direction) {
    scene.Move_Player(direction);
}

sf::Vector2<float> GameModel::Get_player_position() {
    return scene.Get_player_position();
}

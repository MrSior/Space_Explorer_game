//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_GAMECONTROLLER_H
#define SPACE_EXPLORER_GAME_GAMECONTROLLER_H

#include "GameModel.h"
#include "GameRender.h"

class GameController {
private:
    GameModel* m_model;
    GameRender* m_render;
public:
    GameController(GameModel* model, GameRender* render);

    void Run();
};


#endif //SPACE_EXPLORER_GAME_GAMECONTROLLER_H

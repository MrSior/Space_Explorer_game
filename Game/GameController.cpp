//
// Created by Семён Чубенко on 02.02.2022.
//

#include "GameController.h"

GameController::GameController(GameModel *model, GameRender *render) {
    m_model = model;
    m_render = render;
}

void GameController::Run() {
    sf::Event event;
    while (m_render->window().isOpen()) {
        while (m_render->window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_render->window().close();
            }
//            if (event.type == sf::Event::KeyPressed){
//                if (event.key.code == sf::Keyboard::W){
//                    m_model->Move_Player(sf::Vector2<float> (0, -1));
//                }
//                if (event.key.code == sf::Keyboard::S){
//                    m_model->Move_Player(sf::Vector2<float> (0, 1));
//                }
//            }
        }
        m_model->scene.player.Update();
        m_render -> Render();
    }
}

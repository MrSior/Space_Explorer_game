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
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.key.code == sf::Mouse::Button::Left){
                    if (!m_model->scene->is_player_dead) {
                        m_model->scene->Create_bullet();
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space) {
                    if (m_model->is_game_end) {
                        delete m_model->scene;
                        m_model->scene = new Scene();
                        m_model->is_game_end = false;
                        m_model->is_menu_open = false;
                    } else {
                        m_model->is_menu_open = false;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape) {
                    m_model->is_menu_open = true;
                }
            }
        }
        if (!m_model->scene->is_player_dead && !m_model->is_menu_open){
            m_model->scene->Update();
            m_model->scene->player.Look_at(m_render->Get_mouse_position());
        }

        if (m_model->scene->is_player_dead && m_model->scene->explosion_animations.empty()) {
            m_model->is_menu_open = true;
            m_model->is_game_end = true;
        }
        if (!m_model->is_menu_open) {
            for (auto & explosion_animation : m_model->scene->explosion_animations) {
                explosion_animation->Update();
            }
        }
        m_render -> Render();
    }
}

//
// Created by Семён Чубенко on 02.02.2022.
//

#include "GameRender.h"

GameRender::GameRender(GameModel *model) {
    m_model = model;
    Init();
}

void GameRender::Init() {
//    window_x = 2880;
//    window_y = 1800;
    window_x = float (sf::VideoMode::getDesktopMode().width);
    window_y = float (sf::VideoMode::getDesktopMode().height);
    m_window.create(sf::VideoMode(window_x, window_y), "Text Editor", sf::Style::Fullscreen);
}

void GameRender::Render() {
    m_window.clear(sf::Color(9,31,47));
    m_window.draw(*this);
    m_window.display();
}

void GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(m_model->scene.player.Get_sprite());
}

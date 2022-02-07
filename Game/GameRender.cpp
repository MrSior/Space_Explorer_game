//
// Created by Семён Чубенко on 02.02.2022.
//

#include "GameRender.h"
#include "iostream"

GameRender::GameRender(GameModel *model) {
    m_model = model;
    Init();
}

void GameRender::Init() {
//    window_x = 2880;
//    window_y = 1800;
    window_x = float (sf::VideoMode::getDesktopMode().width);
    window_y = float (sf::VideoMode::getDesktopMode().height);
    background_texture.loadFromFile("./Images/space_background_v2.png");
    background.setTexture(background_texture);
    background.setScale(1.5, 5.f / 3.f);
    m_window.create(sf::VideoMode(window_x, window_y), "Text Editor", sf::Style::Fullscreen);
}

void GameRender::Render() {
    m_window.clear(sf::Color(9,31,47));
    m_window.draw(*this);
    m_window.display();
}

void GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(background);

    target.draw(m_model->scene.player.Get_sprite());
    for (auto i : m_model->scene.bullets) {
        target.draw(i->Get_sprite());
    }

    for (auto i : m_model->scene.enemy_bullets) {
        target.draw(i->Get_sprite());
    }

    for (auto i : m_model->scene.enemies) {
        target.draw(i->Get_sprite());
    }
}

sf::Vector2i GameRender::Get_mouse_position() {
    return sf::Mouse::getPosition(m_window);
}


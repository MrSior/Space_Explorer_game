//
// Created by Семён Чубенко on 02.02.2022.
//

#include "GameRender.h"

GameRender::GameRender(GameModel *model) {
    m_model = model;
    Init();
}

void GameRender::Init() {
    window_x = 2880;
    window_y = 1800;
    m_window.create(sf::VideoMode(window_x, window_y), "Text Editor", sf::Style::Fullscreen);
}

void GameRender::Render() {
    m_window.clear(sf::Color(9,31,47));
    m_window.draw(*this);
    m_window.display();
}

void GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(10, window_y - rectangle.getSize().y);
    target.draw(rectangle);
}

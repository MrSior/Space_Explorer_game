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
    font.loadFromFile("./font/ARCADECLASSIC.TTF");
}

void GameRender::Render() {
    m_window.clear(sf::Color(9,31,47));
    m_window.draw(*this);
    m_window.display();
}

void GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(background);

    sf::RectangleShape menu_background(sf::Vector2f (float (sf::VideoMode::getDesktopMode().width),
                                                          float (sf::VideoMode::getDesktopMode().height)));
    menu_background.setFillColor(sf::Color(150, 150, 150, 150));

    for (auto i : m_model->scene->bullets) {
        target.draw(i->Get_sprite());
    }

    for (auto i : m_model->scene->enemy_bullets) {
        target.draw(i->Get_sprite());
    }

    for (auto i : m_model->scene->enemies) {
        target.draw(i->Get_sprite());
    }

    target.draw(m_model->scene->player.Get_sprite());

    sf::Text score_text;
    score_text.setFont(font);
    score_text.setString("Score " + std::to_string(m_model->scene->score));
    score_text.setCharacterSize(80);
    score_text.setFillColor(sf::Color::Yellow);
    score_text.setPosition(30, 30);
    target.draw(score_text);

    for (int i = 0; i < m_model->scene->explosion_animations.size(); ++i) {
        m_model->scene->explosion_animations[i]->Update();
        if (m_model->scene->explosion_animations[i]->Get_is_finished()){
            delete m_model->scene->explosion_animations[i];
            m_model->scene->explosion_animations.erase(m_model->scene->explosion_animations.begin() + i);
        } else {
            target.draw(m_model->scene->explosion_animations[i]->Get_sprite());
        }
    }

    if (m_model->is_menu_open){
        target.draw(menu_background);
    }
}

sf::Vector2i GameRender::Get_mouse_position() {
    return sf::Mouse::getPosition(m_window);
}


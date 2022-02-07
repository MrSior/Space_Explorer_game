//
// Created by Семён Чубенко on 02.02.2022.
//

#ifndef SPACE_EXPLORER_GAME_GAMERENDER_H
#define SPACE_EXPLORER_GAME_GAMERENDER_H

#include "SFML/Graphics.hpp"
#include "GameModel.h"

class GameRender : public sf::Drawable, public sf::Transformable{
private:
    GameModel* m_model;
    sf::RenderWindow m_window;
    sf::Texture background_texture;
    sf::Sprite background;
    float window_x, window_y;
public:
    GameRender(GameModel* model);
    sf::RenderWindow& window() { return m_window; };

    void Init();
    void Render();
    sf::Vector2i Get_mouse_position();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //SPACE_EXPLORER_GAME_GAMERENDER_H

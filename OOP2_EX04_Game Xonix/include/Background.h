#pragma once
#include <SFML/Graphics.hpp>
#include "GameException.h"

class Background {
public:
    Background(const std::string& path, const sf::Vector2f& size);

    void background(sf::RenderWindow& window);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

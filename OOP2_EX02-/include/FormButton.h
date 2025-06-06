#pragma once
#include <SFML/Graphics.hpp>


class FormButton {

public:
    FormButton(const sf::Vector2f& size, const sf::Vector2f& position,
        const sf::Color& color, const std::string& text, const sf::Font& font, unsigned int textSize);

    void draw(sf::RenderWindow& window) const;
    bool contains(const sf::Vector2f& point) const;

private:
    sf::RectangleShape m_shape;
    sf::Text m_text;
};


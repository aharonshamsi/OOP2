#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Title {
public:
    Title(const std::string& text, const sf::Font& font, unsigned int fontSize);

    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Text m_text;
};

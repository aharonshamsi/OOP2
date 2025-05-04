#include "Title.h"

Title::Title(const std::string& text, const sf::Font& font, unsigned int fontSize)
{
    m_text.setString(text);
    m_text.setFont(font);
    m_text.setCharacterSize(fontSize);
    m_text.setFillColor(sf::Color(20, 20, 20)); 
    m_text.setStyle(sf::Text::Bold);
}

void Title::setPosition(float x, float y)
{
    m_text.setPosition(x, y);
}

void Title::draw(sf::RenderWindow& window) const
{
    window.draw(m_text);
}

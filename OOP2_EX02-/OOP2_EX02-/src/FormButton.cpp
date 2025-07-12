#include "FormButton.h"

FormButton::FormButton(const sf::Vector2f& size, const sf::Vector2f& position,
    const sf::Color& color, const std::string& text, const sf::Font& font, unsigned int textSize)
{
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setFillColor(color);

    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(textSize);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(position.x + 30, position.y + 10); 
}

void FormButton::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
    window.draw(m_text);
}


bool FormButton::contains(const sf::Vector2f& point) const {
    return m_shape.getGlobalBounds().contains(point);
}

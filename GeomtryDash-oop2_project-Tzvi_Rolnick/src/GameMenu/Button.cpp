#include "GameMenu/Button.h"

Button::Button(const sf::Vector2f& location)
	:m_location(location)
{}

bool Button::isPressed(const sf::Vector2f& mousePos) const
{
	return m_sprite.getGlobalBounds().contains(mousePos);
}

void Button::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	window.draw(m_sprite);
}

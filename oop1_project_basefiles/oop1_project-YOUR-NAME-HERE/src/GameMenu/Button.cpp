#include "GameMenu/Button.h"

Button::Button(const TypeButton& type, const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:m_type(type), m_location(location)/*, m_pressed(false)*/
{
	updateSpritesForAll(wantedSize);
}



void Button::updateSpritesForAll(const sf::Vector2f& wantedSize)
{
	switch (m_type)
	{
	case TypeButton::Start:
		m_sprite = ImagesButton::getSpinte(TypeButton::Start, wantedSize);
		break;

	case TypeButton::Store:
		m_sprite = ImagesButton::getSpinte(TypeButton::Store, wantedSize);
		break;

	case TypeButton::Help:
		m_sprite = ImagesButton::getSpinte(TypeButton::Help, wantedSize);
		break;

	case TypeButton::Exit:
		m_sprite = ImagesButton::getSpinte(TypeButton::Exit, wantedSize);
		break;

	default:
		break;
	}
}


void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

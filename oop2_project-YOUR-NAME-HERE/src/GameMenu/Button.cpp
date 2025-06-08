#include "GameMenu/Button.h"

Button::Button(const TypeButton& type, const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:m_type(type), m_location(location)
{
	updateSpritesForAll(wantedSize);
}

bool Button::isPressed(const sf::Vector2f& mousePos) const
{
	return mousePos.x >= m_location.x && mousePos.x <= m_location.x + ButtonData::SIZE_BUTTON.x &&
		mousePos.y >= m_location.y && mousePos.y <= m_location.y + ButtonData::SIZE_BUTTON.y;
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

	case TypeButton::Watch:
		m_sprite = ImagesButton::getSpinte(TypeButton::Watch, wantedSize);
		break;

	case TypeButton::GitHub:
		m_sprite = ImagesButton::getSpinte(TypeButton::GitHub, wantedSize);
		break;

	default:
		break;
	}
}


void Button::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location); // עדכון מיקום התמונה
	window.draw(m_sprite);
}

#include "Object.h"


Object::Object(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ObjectType& type)
	:m_location(location), m_type(type)
{
	setSpriteByType(wantedSize);
	m_picture.setPosition(m_location);
}

void Object::draw(sf::RenderWindow& window)
{
	m_picture.setPosition(m_location);
	window.draw(m_picture);
}



void Object::setSpriteByType(const sf::Vector2f& wantedSize)
{
	switch (m_type)
	{
	case ObjectType::Player:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;

	case ObjectType::Enemy:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;

	default:
		break;
	}
}

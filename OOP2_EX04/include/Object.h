#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "Images.h"

class Object {

public:
	Object(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ObjectType& type);

protected:

	ObjectType m_type;
	sf::Vector2f m_location; // מיקום האובייקט
	sf::Sprite m_picture; // תמונה

private:
	void setSpriteByType(const sf::Vector2f& wantedSize);
};
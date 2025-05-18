#pragma once
#include "Object.h"

class MovingObject : public Object{

public:
	MovingObject(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ObjectType& type);

private:
	const sf::Vector2f m_firstLocation;
	sf::Vector2f m_direction;
};

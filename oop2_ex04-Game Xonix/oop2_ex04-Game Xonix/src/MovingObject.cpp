#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f& location, const sf::Vector2f& wantedSize, 
							const ObjectType& type)
	:Object(location, wantedSize, type),
	m_firstLocation(location), m_direction(0.f, 0.f)
{}



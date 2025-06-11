#pragma once
#include "GameObject/StaticObject/StaticObject.h"

class Obstacle : public StaticObject
{
public:
	Obstacle(sf::Vector2f location, sf::Sprite sprite);
	virtual ~Obstacle() = default;

	virtual void handleCollision(Object&);

};
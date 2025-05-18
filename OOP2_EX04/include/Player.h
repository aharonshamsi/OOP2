#pragma once
#include "MovingObject.h"

class Player : public MovingObject {

public:
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

};
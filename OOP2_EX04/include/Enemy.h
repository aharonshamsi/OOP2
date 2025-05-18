#pragma once
#include "Object.h"

class Enemy : public Object {

public:
	Enemy(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void d(sf::RenderWindow& a)
	{
		a.draw(m_picture);     // מצייר את הספרייט
	}

};

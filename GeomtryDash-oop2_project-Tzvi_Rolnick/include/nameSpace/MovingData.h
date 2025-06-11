#pragma once
#include <SFML/Graphics.hpp>

namespace DIRECTION 
{
	sf::Vector2f UP{ 0.f, -1.f };
	sf::Vector2f DOWN{ 0.f, 1.f };
}

namespace JUMP
{
	const int SPEED = 150; // Speed of the player
	const int MAX_HEIGHT = 200; // Height of the jump
}

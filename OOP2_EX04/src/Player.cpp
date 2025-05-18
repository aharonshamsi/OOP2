#include "Player.h"

Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:MovingObject(location, wantedSize, ObjectType::Player)
{}


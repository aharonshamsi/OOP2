#include "GameObject/StaticObject/Obstacle.h"

Obstacle::Obstacle(sf::Vector2f location, sf::Sprite sprite) :StaticObject(location, sprite)
{
	// Additional initialization for Obstacle if needed
}

void Obstacle::handleCollision(Object& other)
{
	other.handleCollision(*this); // Notify the other object about the collision
}

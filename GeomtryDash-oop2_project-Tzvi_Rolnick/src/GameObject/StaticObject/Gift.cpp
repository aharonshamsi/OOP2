#include "GameObject/StaticObject/Gift.h"

Gift::Gift(sf::Vector2f location, sf::Sprite sprite)
	: StaticObject(location, sprite) {
}

void Gift::handleCollision(Object& other) {
	// Notify the other object about the collision
	other.handleCollision(*this);
	std::cout << "Gift collided with another object." << std::endl;
	// Additional logic for handling collision with a gift can be added here
}
#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Object(location, wantedSize, ObjectType::Enemy)
{}
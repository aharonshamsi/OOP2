#include "GameObject/MovingObject/Enemy.h"
#include "GameObject/MovingObject/Player.h"
#include "GameObject/Factory.h"
#include "GameObject/Images/TypeObject.h"

Enemy::Enemy(sf::Vector2f location, sf::Sprite sprite)
	: MovingObject(location, sprite) {
}
bool Enemy::m_registerit = Factory::registerIt('@',
	[](sf::Vector2f loc, const ImagesObject& images, const TypeObject) -> std::unique_ptr<Object> {
		return std::make_unique<Enemy>(loc, images.getSpriteObject(TypeObject::Enemy));
	});

void Enemy::move(float deltaTime)
{
	// Moves the enemy to the right until it collides with something, then changes direction.

	/*m_location += m_direction * (150 * deltaTime);*/
}

void Enemy::handleCollision(StaticObject& other)
{
	std::cout << "Enemy collided with another object." << std::endl;
	m_location.x -= m_direction.x * 10; // Adjust position to avoid sticking
	m_direction = -m_direction; // change direction when colliding with another object
}

void Enemy::handleCollision(Player& player)
{
	std::cout << "Enemy collided with Player." << std::endl;
	//player.handleCollision(*this); // Notify the player about the collision.
}

//void Enemy::handleCollision(Obstacle& obstacle)
//{
//	std::cout << "Enemy collided with Obstacle." << std::endl;
//	//m_direction = -m_direction; // change direction when colliding with an obstacle
//}

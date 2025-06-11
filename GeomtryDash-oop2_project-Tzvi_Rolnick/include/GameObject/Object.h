#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
#include <iostream>

class StaticObject;
class Player;
class Enemy;
class Obstacle;

class Object
{
public:
	Object(sf::Vector2f location, sf::Sprite sprite);
	virtual ~Object() = default;
	virtual void draw(sf::RenderWindow& window);

	bool checkCollision(Object&) const;
	bool collidesWith(Object&) const;

	virtual void handleCollision(Object&) {};
	virtual void handleCollision(StaticObject&) {};
	virtual void handleCollision(Player&) {};
	virtual void handleCollision(Enemy&) {};
	virtual void handleCollision(Obstacle&) {};

protected:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;

	// moveByView is used to move the object by the view's position
	virtual void moveByView(float&);
};
#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "Images.h"
#include <iostream>
#include "GameInfo.h"

class Player;
class Enemy;

class Object {

public:

	Object(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ObjectType& type);
	virtual ~Object() = default; 

	void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation() const { return m_location; };

	virtual sf::FloatRect getGlobalBounds() const = 0;
	virtual void restartLoc() = 0;

	virtual void handleCollision(Object& object, GameInfo& gameInfo) = 0;
	virtual void handleCollision(Enemy& enemy, GameInfo& gameInfo) = 0;
	virtual void handleCollision(Player& player, GameInfo& gameInfo) = 0;

protected:
	ObjectType m_type;
	sf::Vector2f m_location; 
	sf::Sprite m_picture; 

private:
	void setSpriteByType(const sf::Vector2f& wantedSize);
};
#pragma once
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"

class Enemy : public MovingObject
{
public:
	Enemy(sf::Vector2f location, sf::Sprite sprite);
	~Enemy() override = default;
	virtual void move(float deltaTime) override;

	virtual void handleCollision(StaticObject&) override;
	virtual void handleCollision(Player&) override;
	// virtual void handleCollision(Obstacle&) override;
	// virtual void handleCollision(...&) override;
	// virtual void handleCollision(...&) override;

private:
	sf::Vector2f m_direction = { 1.f, 0.f };	// Default direction to the right

};

/*
* צריך לזוז ימינה עד שהוא נפגש עם משהו אחר ואז יחליף כיוון
* התנגשות עם ירייה והוא מת
* התנגשות עם שחקן והוא מת
* עידכון של אינפורמציה 
* 
*/


// אני כותב בסוף את מחלקת ירייה 
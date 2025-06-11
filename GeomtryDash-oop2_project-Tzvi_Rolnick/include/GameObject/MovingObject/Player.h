#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"

class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite);
	~Player() override = default;

	void startJump();
	void move(float deltaTime) override; // add move right here on the World. with View.


	virtual void handleCollision(Object&) override;
  //  virtual void handleCollision(Enemy&) override; 

private:

	sf::Vector2f m_firstLoc;
	sf::Vector2f m_nextLoc;

	sf::Vector2f m_firstLocBeforeJump;
	bool m_jumping = false;
	bool  m_isFalling = false;    // I am falling now = true.

	void moveUpToDirection(float deltaTime);
	void updateModeDirection();
};
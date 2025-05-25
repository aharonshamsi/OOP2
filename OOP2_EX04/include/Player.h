#pragma once
#include "MovingObject.h"
#include "Enemy.h"

class Player : public MovingObject {

public:
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo) override;
	void restartLoc() override;

	virtual sf::FloatRect getGlobalBounds() const override;

	void handleCollision(Object& object, GameInfo& gameInfo) override;
	void handleCollision(Enemy& enemy, GameInfo& gameInfo) override;
	void handleCollision(Player& player, GameInfo& gameInfo) override {};


private:
	void trailMarker(const sf::Vector2f& newLocation, TileBoard& boardTiles);
	const sf::Vector2f getWantedDirection() const;

	bool checkSelfTrailCollision(TileBoard& boardTiles);

};
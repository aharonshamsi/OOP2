#pragma once
#include "MovingObject.h"
#include "Enemy.h"

class Player : public MovingObject {

public:
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo) override;
	virtual sf::FloatRect getGlobalBounds() const override;
	void restartLoc() override;

	void handleCollision(Object& object, GameInfo& gameInfo) override;
	void handleCollision(Enemy& enemy, GameInfo& gameInfo) override;
	void handleCollision(Player& player, GameInfo& gameInfo) override {};


private:
	void trailMarker(const sf::Vector2f& newLocation, TileBoard& boardTiles);
	const sf::Vector2f getWantedDirection() const;

	void handleDirectionChange(TileBoard& boardTiles);
	bool handleBoundaryLimits(GameInfo& gameInfo);
	void updatePosition(const sf::Vector2f& newLocation, TileBoard& boardTiles);
	void handleTileType(TileBoard& boardTiles, GameInfo& gameInfo, ObjectType& prevTileType);
};
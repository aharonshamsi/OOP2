#pragma once
#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject {

public:
	Enemy(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo) override;

	virtual sf::FloatRect getGlobalBounds() const override;

	void handleCollision(Object& object, GameInfo& gameInfo) override;
	void handleCollision(Enemy& enemy, GameInfo& gameInfo) override {};
	void handleCollision(Player& player, GameInfo& gameInfo) override;

private:
	void newDiractoin(const TileBoard& boardTiles, const sf::Vector2f& location);

	void floodFillArea(TileBoard& boardTiles, GameInfo& gameInfo, int row, int col);
	int countFilledTiles(TileBoard& boardTiles);

	bool m_recentTurn = false; // דגל שמונע שינוי כיוון חוזר מיד אחרי הקודם
	sf::Vector2i m_prevTile = {-1, -1};

};

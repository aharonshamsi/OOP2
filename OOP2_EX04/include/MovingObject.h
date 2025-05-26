#pragma once
#include "Object.h"
#include "MovementConsts.h"
#include "TileBoard.h"
#include "GameInfo.h"


class MovingObject : public Object{

public:
	MovingObject(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ObjectType& type);

	void restartLoc() override {};
	virtual void move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo) = 0;

protected:
	const sf::Vector2f m_firstLocation;
	sf::Vector2f m_direction;
};

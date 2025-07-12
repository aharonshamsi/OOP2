#include "Player.h"

Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:MovingObject(location, wantedSize, ObjectType::Player)
{}


void Player::restartLoc()
{
	m_location = m_firstLocation;
}

const sf::Vector2f Player::getWantedDirection() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return MovementConsts::DIRECTION_RIGHT;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return MovementConsts::DIRECTION_LEFT;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return MovementConsts::DIRECTION_UP;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return MovementConsts::DIRECTION_DOWN;

	return MovementConsts::NO_DIRECTION;
}

sf::FloatRect Player::getGlobalBounds() const
{
	return m_picture.getGlobalBounds();
}

void Player::handleCollision(Object& object, GameInfo& gameInfo) {
	object.handleCollision(*this, gameInfo);  
}


void Player::handleCollision(Enemy& enemy, GameInfo& gameInfo) {
	if (this->getGlobalBounds().intersects(enemy.getGlobalBounds())) {
		gameInfo.setIsViolation(true);
	}
}

void Player::move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo)
{
	static ObjectType prevTileType = ObjectType::Frame;

	handleDirectionChange(boardTiles);

	if (handleBoundaryLimits(gameInfo)) {
		return;
	}

	sf::Vector2f delta = m_direction * seconds * MovementConsts::MOVE_PIXEL_PLAYER;
	sf::Vector2f newLocation = m_location + delta;

	updatePosition(newLocation, boardTiles);

	handleTileType(boardTiles, gameInfo, prevTileType);
}


void Player::handleDirectionChange(TileBoard& boardTiles)
{
	sf::Vector2f lastDirection = getWantedDirection();
	if (lastDirection != m_direction) {
		m_location = boardTiles.getTileLoc(m_location); 
	}
	m_direction = getWantedDirection();
}


bool Player::handleBoundaryLimits(GameInfo& gameInfo)
{
	const float Width = gameInfo.getSizeWindow().x - GameConsts::sizeTile.x;
	float Height = gameInfo.getSizeWindow().y - GameConsts::HIGHT_SHAPE_INFO - GameConsts::sizeTile.y;

	if (m_location.x >= Width && m_direction == MovementConsts::DIRECTION_RIGHT) {
		m_location.x = Width;
		return true; 
	}
	else if (m_location.y >= Height && m_direction == MovementConsts::DIRECTION_DOWN) {
		m_location.y = Height;
		return true;
	}
	return false;
}

void Player::updatePosition(const sf::Vector2f& newLocation, TileBoard& boardTiles)
{
	if (!boardTiles.isPlayerOutOfBounds(newLocation)) {
		sf::Vector2f delta = newLocation - m_location;
		m_picture.move(delta);
		m_location = newLocation;
		trailMarker(newLocation, boardTiles);
	}
	else {
		m_location = boardTiles.getTileLoc(m_location);
	}
}

void Player::handleTileType(TileBoard& boardTiles, GameInfo& gameInfo, ObjectType& prevTileType)
{
	ObjectType currentTileType = boardTiles.getTypeAtLocation(boardTiles.getTileLoc(m_location));

	if ((currentTileType == ObjectType::Frame || currentTileType == ObjectType::Filled) &&
		(prevTileType == ObjectType::Empty || prevTileType == ObjectType::Trail)) {
		gameInfo.setNeedAreaCheck(true);
	}
	prevTileType = currentTileType;
}


void Player::trailMarker(const sf::Vector2f& newLocation, TileBoard& boardTiles)
{
	sf::Vector2f locMarker = boardTiles.getTileLoc(newLocation);

	// If the direction is left – we will check the tile to the right
	if (m_direction == MovementConsts::DIRECTION_LEFT) {
		sf::Vector2f loc(newLocation.x + GameConsts::sizeTile.x, newLocation.y);
		if (boardTiles.inArea(loc) &&
			!boardTiles.isframeTile(boardTiles.getTileLoc(loc)) &&
			boardTiles.getTypeAtLocation(loc) != ObjectType::Filled)
		{
			boardTiles.getTile(loc)->setType(ObjectType::Trail);
		}
	}

	// The direction is up – we will check the tile below. 
	else if (m_direction == MovementConsts::DIRECTION_UP) {
		sf::Vector2f loc(newLocation.x, newLocation.y + GameConsts::sizeTile.y);
		if (boardTiles.inArea(loc) &&
			!boardTiles.isframeTile(boardTiles.getTileLoc(loc)) &&
			boardTiles.getTypeAtLocation(loc) != ObjectType::Filled)
		{
			boardTiles.getTile(loc)->setType(ObjectType::Trail);
		}
	}

	else if (boardTiles.inArea(newLocation) &&
		!boardTiles.isframeTile(boardTiles.getTileLoc(newLocation)) &&
		boardTiles.getTypeAtLocation(newLocation) != ObjectType::Filled)
	{
		boardTiles.getTile(newLocation)->setType(ObjectType::Trail);
	}
}





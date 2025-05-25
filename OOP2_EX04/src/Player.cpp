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
	// השלב הראשון - מזמן את פונקציית ההתמחות מהצד השני
	object.handleCollision(*this, gameInfo);  // -> Enemy::handleCollision(Player&)
}


void Player::handleCollision(Enemy& enemy, GameInfo& gameInfo) {
	if (this->getGlobalBounds().intersects(enemy.getGlobalBounds())) {
		gameInfo.setIsViolation(true);
		// אם יש חפיפה בין הגבולות
	}
}



void Player::move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo)
{
	static ObjectType prevTileType = ObjectType::Frame; // מצב קודם של אריח – מתחילים ממסגרת

	// אם שינה כיוון נעדכן את המיקום לראש האריח
	sf::Vector2f lastDirection = getWantedDirection();
	if (lastDirection != m_direction) {
		m_location = boardTiles.getTileLoc(m_location);
	}

	m_direction = getWantedDirection();
	//===========
	// חישוב מיקום חדש
	sf::Vector2f newLocation = m_location + (m_direction * seconds * MovementConsts::MOVE_PIXEL_PLAYER);

	// בדיקת תחום לוח
	if (boardTiles.inArea(newLocation)) {
		m_picture.move(newLocation);
		m_location = newLocation;
		trailMarker(newLocation, boardTiles); // סימון שביל
	}

	// בדיקת סוג האריח הנוכחי

	ObjectType currentTileType = boardTiles.getTypeAtLocation(boardTiles.getTileLoc(m_location));

	// עדכון needAreaCheck אם עבר מ-Empty ל-Frame או ל-Filled (שטח שכבר נכבש)
	if ((currentTileType == ObjectType::Frame || currentTileType == ObjectType::Filled) &&
		(prevTileType == ObjectType::Empty || prevTileType == ObjectType::Trail))
	{
		std::cout << "j\n";
		gameInfo.setNeedAreaCheck(true);
	}


	prevTileType = currentTileType;
}


void Player::trailMarker(const sf::Vector2f& newLocation, TileBoard& boardTiles)
{
	sf::Vector2f locMarker = boardTiles.getTileLoc(newLocation);

	// אם הכיוון הוא שמאלה – נבדוק אריח ימינה
	if (m_direction == MovementConsts::DIRECTION_LEFT) {
		sf::Vector2f loc(newLocation.x + GameConsts::sizeTile.x, newLocation.y);
		if (boardTiles.inArea(loc) &&
			!boardTiles.isframeTile(boardTiles.getTileLoc(loc)) &&
			boardTiles.getTypeAtLocation(loc) != ObjectType::Filled)
		{
			boardTiles.getTile(loc)->setType(ObjectType::Trail);
		}
	}
	// אם הכיוון הוא למעלה – נבדוק אריח למטה
	else if (m_direction == MovementConsts::DIRECTION_UP) {
		sf::Vector2f loc(newLocation.x, newLocation.y + GameConsts::sizeTile.y);
		if (boardTiles.inArea(loc) &&
			!boardTiles.isframeTile(boardTiles.getTileLoc(loc)) &&
			boardTiles.getTypeAtLocation(loc) != ObjectType::Filled)
		{
			boardTiles.getTile(loc)->setType(ObjectType::Trail);
		}
	}
	// כל כיוון אחר – מסמנים את המיקום עצמו אם הוא לא מסגרת ולא Filled
	else if (boardTiles.inArea(newLocation) &&
		!boardTiles.isframeTile(boardTiles.getTileLoc(newLocation)) &&
		boardTiles.getTypeAtLocation(newLocation) != ObjectType::Filled)
	{
		boardTiles.getTile(newLocation)->setType(ObjectType::Trail);
	}
}





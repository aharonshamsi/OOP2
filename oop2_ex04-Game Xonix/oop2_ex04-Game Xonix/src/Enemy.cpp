#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
    :MovingObject(location, wantedSize, ObjectType::Enemy)
{
    m_direction = sf::Vector2f(1.f, 1.f); 
}


sf::FloatRect Enemy::getGlobalBounds() const
{
    return m_picture.getGlobalBounds(); 
}

void Enemy::handleCollision(Object& object, GameInfo& gameInfo) {
    object.handleCollision(*this, gameInfo); 
}

void Enemy::handleCollision(Player& player, GameInfo& gameInfo) {
    if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
        gameInfo.setIsViolation(true);
    }
}



void Enemy::move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo)
{
    sf::Vector2f velocity = m_direction * seconds * MovementConsts::MOVE_PIXEL_ENEMY;
    sf::Vector2f newLocation = m_location + velocity;

    int row = static_cast<int>(newLocation.y / boardTiles.getSizeTile().y);
    int col = static_cast<int>(newLocation.x / boardTiles.getSizeTile().x);

    if (!boardTiles.inArea(newLocation) ||
        boardTiles.isframeTileForMove(newLocation) ||
        boardTiles.getTypeAtLocation(newLocation) == ObjectType::Filled)
    {
        newDiractoin(boardTiles, newLocation);
        return; 
    }

    if (boardTiles.getType(row, col) == ObjectType::Trail) {
        gameInfo.setIsViolation(true);
    }
    m_picture.move(velocity);
    m_location = newLocation;


    // If necessary, perform recursion to capture
    if (gameInfo.getNeedAreaCheck()) {
        floodFillArea(boardTiles, gameInfo, row, col);

        int filled = countFilledTiles(boardTiles); 
        int total = (boardTiles.getRows() - 2) * (boardTiles.getCols() - 2); 

        gameInfo.updateCapturedArea(filled, total); 
        gameInfo.addScoreForCaptured(filled);
    }

}


int Enemy::countFilledTiles(TileBoard& boardTiles) {
    int count = 0;
    for (int row = 0; row < boardTiles.getRows(); row++) {
        for (int col = 0; col < boardTiles.getCols(); col++) {
            Tile& tile = boardTiles.getTile(row, col);

            if (!tile.getIsVisited() && tile.getType() != ObjectType::Frame) {
                count++;
            }
        }
    }
    return count;
}



void Enemy::newDiractoin(const TileBoard& boardTiles, const sf::Vector2f& location)
{
    int row = static_cast<int>(location.y / GameConsts::sizeTile.y);
    int col = static_cast<int>(location.x / GameConsts::sizeTile.x);

    bool hitObstacle = boardTiles.isframeTileForMove(location);

    bool filled = boardTiles.getType(row, col) == ObjectType::Filled;
    if (filled)
        m_recentTurn = true;

    if (hitObstacle && !m_recentTurn)
        CollisionUp();

    else if (m_recentTurn) {
        bool  arecentFlip = boardTiles.isframeTileForMove(location) ||
            boardTiles.getTypeAtLocation(location) == ObjectType::Filled;

     if (arecentFlip)
            CollisionDown();
    }


}


void Enemy::floodFillArea(TileBoard& boardTiles, GameInfo& gameInfo, int row, int col)
{
    if (row < 0 || col < 0 || row >= boardTiles.getRows() || col >= boardTiles.getCols())
        return;

    Tile& tile = boardTiles.getTile(row, col);

    if (tile.getIsVisited() || tile.getType() != ObjectType::Empty)
        return;

    tile.setVisited(true);

    floodFillArea(boardTiles, gameInfo, row - 1, col); 
    floodFillArea(boardTiles, gameInfo, row + 1, col);
    floodFillArea(boardTiles, gameInfo, row, col - 1);
    floodFillArea(boardTiles, gameInfo, row, col + 1);
}



void Enemy::CollisionUp()
{
     if (m_direction == sf::Vector2f(1, 1))
        m_direction = sf::Vector2f(1.f, -1.f); 
    else if (m_direction == sf::Vector2f(1, -1))
        m_direction = sf::Vector2f(-1.f, -1.f);
    else if (m_direction == sf::Vector2f(-1, -1))
        m_direction = sf::Vector2f(-1.f, 1.f);
    else if (m_direction == sf::Vector2f(-1, 1))
        m_direction = sf::Vector2f(1.f, 1.f);
}


void Enemy::CollisionDown()
{
    if (m_direction == sf::Vector2f(1, -1))
        m_direction = sf::Vector2f(1.f, 1.f);
    else if (m_direction == sf::Vector2f(1, 1))
        m_direction = sf::Vector2f(-1.f, 1.f);
    else if (m_direction == sf::Vector2f(-1, 1))
        m_direction = sf::Vector2f(-1.f, -1.f);
    else if (m_direction == sf::Vector2f(-1, -1))
        m_direction = sf::Vector2f(1.f, -1.f);
}

#include "TileBoard.h"
#include <iostream>

TileBoard::TileBoard()
    : m_sizeTile(GameConsts::sizeTile) {}

void TileBoard::initTileBoard(const sf::Vector2f& sizeWindow) {
    m_sizeWindow = sizeWindow;
    m_rows = static_cast<int>((m_sizeWindow.y - GameConsts::HIGHT_SHAPE_INFO) / m_sizeTile.y);
    m_cols = static_cast<int>(m_sizeWindow.x / m_sizeTile.x);

    m_boardTile.clear();
    m_boardTile.resize(m_rows);

    for (int i = 0; i < m_rows; ++i) {
        m_boardTile[i].resize(m_cols);
        for (int j = 0; j < m_cols; ++j) {
            sf::Vector2f location(j * m_sizeTile.x, i * m_sizeTile.y);
            m_boardTile[i][j] = std::make_unique<Tile>(location, ObjectType::Empty);
        }
    }

    markFrameTiles();
}

void TileBoard::markFrameTiles() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (i == 0 || i == m_rows - 1 || j == 0 || j == m_cols - 1) {
                m_boardTile[i][j]->setType(ObjectType::Frame);
            }
        }
    }
}

sf::Vector2f TileBoard::randLocation() const {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> rowDist(1, m_rows - 2);
    std::uniform_int_distribution<> colDist(1, m_cols - 2);

    int row = rowDist(gen);
    int col = colDist(gen);

    return sf::Vector2f(getTileLocByIndex(row, col));
}

void TileBoard::draw(sf::RenderWindow& window) {
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            window.draw(m_boardTile[row][col]->getPicture());
        }
    }
}

sf::Vector2f TileBoard::getTileLoc(const sf::Vector2f& location) {
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);
    return getTileLocByIndex(col, row);
}

sf::Vector2f TileBoard::getTileLocByIndex(int cols, int rows) const {
    return sf::Vector2f(cols * m_sizeTile.x, rows * m_sizeTile.y);
}

bool TileBoard::inArea(const sf::Vector2f& pos) const {
    int row = static_cast<int>(pos.y / GameConsts::sizeTile.y);
    int col = static_cast<int>(pos.x / GameConsts::sizeTile.x);

    return row >= 0 && col >= 0 &&
        row < static_cast<int>(m_boardTile.size()) &&
        col < static_cast<int>(m_boardTile[row].size());
}

bool TileBoard::isframeTile(const sf::Vector2f& location) const {
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);

    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        return false;

    return row == 0 || row == m_rows - 1 || col == 0 || col == m_cols - 1;
}

ObjectType TileBoard::getType(int row, int col) const {
    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
        return m_boardTile[row][col]->getType();

    return ObjectType::Frame;
}

ObjectType TileBoard::getTypeAtLocation(const sf::Vector2f& loc) const {
    int row = static_cast<int>(loc.y / m_sizeTile.y);
    int col = static_cast<int>(loc.x / m_sizeTile.x);

    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
        return m_boardTile[row][col]->getType();

    return ObjectType::Frame;
}

Tile* TileBoard::getTile(const sf::Vector2f& location) {
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);

    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
        return m_boardTile[row][col].get();

    return nullptr;
}

Tile& TileBoard::getTile(int row, int col) {
    return *m_boardTile[row][col];
}

void TileBoard::restartTrail() {
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            if (m_boardTile[row][col]->getType() == ObjectType::Trail)
                m_boardTile[row][col]->setType(ObjectType::Empty);
        }
    }
}

void TileBoard::markCapturedArea() {
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            Tile& tile = *m_boardTile[row][col];

            if (!tile.getIsVisited() && tile.getType() != ObjectType::Frame) {
                tile.setType(ObjectType::Filled);
            }

            tile.setVisited(false);
        }
    }
}

bool TileBoard::isframeTileForMove(const sf::Vector2f& location) const {
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);

    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        return false;

    return row == 0 || row == m_rows - 2 || col == 0 || col == m_cols - 2;
}

bool TileBoard::isPlayerOutOfBounds(const sf::Vector2f& location) const
{
    const float boardWidth = getCols() * GameConsts::sizeTile.x;
    const float boardHeight = getRows() * GameConsts::sizeTile.y;
    const float epsilon = 0.01f;

    return location.x < 0.0f ||
        location.y < 0.0f ||
        location.x > boardWidth - epsilon ||
        location.y > boardHeight - epsilon;
}

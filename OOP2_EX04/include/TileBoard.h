#pragma once

#include "GameConsts.h"
#include "MovementConsts.h"
#include "Tile.h"

#include <vector>
#include <memory>
#include <random>

class TileBoard {
public:
    TileBoard();

    void initTileBoard(const sf::Vector2f& sizeWindow);
    void markFrameTiles();

    int getRows() const { return m_rows; }
    int getCols() const { return m_cols; }
    sf::Vector2f getSizeTile() { return m_sizeTile; }

    sf::Vector2f randLocation() const;
    void draw(sf::RenderWindow& window);

    sf::Vector2f getTileLoc(const sf::Vector2f& location);
    sf::Vector2f getTileLocByIndex(int cols, int rows) const;

    bool inArea(const sf::Vector2f& newLocation) const;
    bool isframeTile(const sf::Vector2f& location) const;
    bool isframeTileForMove(const sf::Vector2f& location) const;
    bool isPlayerOutOfBounds(const sf::Vector2f& location) const;

    ObjectType getType(int row, int col) const;
    ObjectType getTypeAtLocation(const sf::Vector2f& loc) const;

    Tile* getTile(const sf::Vector2f& location);
    Tile& getTile(int row, int col);

    void restartTrail();
    void markCapturedArea();

private:
    int m_rows;
    int m_cols;
    sf::Vector2f m_sizeWindow;
    sf::Vector2f m_sizeTile;
    std::vector<std::vector<std::unique_ptr<Tile>>> m_boardTile;
};

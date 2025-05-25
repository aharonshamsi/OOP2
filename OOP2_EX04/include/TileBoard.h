#pragma once
#include "GameConsts.h"
#include "MovementConsts.h"

#include "vector"
#include <memory>
#include <random> 

#include "Tile.h"


class TileBoard {

public:
	TileBoard();

	void initTileBoard(const sf::Vector2f& sizeWindow);
	void markFrameTiles(); // מעדכן מזזה של מסגרת

	int getRows() const { return m_rows; }
	int getCols() const { return m_cols; }
	sf::Vector2f getSizeTile() { return m_sizeTile; };
	sf::Vector2f randLocation() const; // מגרילה מיקום בלוח


	void draw(sf::RenderWindow& window);

	sf::Vector2f getTileLoc(const sf::Vector2f& location); // מקבלת מיקום ומחזירה מיקום אריחי 
	sf::Vector2f getTileLocByIndex(int cols, int rows) const; // מקבלת אינדקס ומחזירה את המיקום האריחי העליון שלו

	bool inArea(const sf::Vector2f& newLocation) const; // גבולות בתוך הלוח
	bool isframeTile(const sf::Vector2f& location) const;\

	ObjectType getType(int row, int col)const;
	ObjectType getTypeAtLocation(const sf::Vector2f& loc) const; // לבדוק האם השתמשתי 

	Tile* getTile(const sf::Vector2f& location); // מחזירה מצביע על אריח על ידי שקיבלה מיקום כללי שלו

	void restartTrail(); // מאפסת חלון לאחר פסול 
	Tile& getTile(int row, int col); // מחזיר רפרנס למאריח
	
	void markCapturedArea();
	bool isframeTileForMove(const sf::Vector2f& location) const;
	//bool inAreaMove(const sf::Vector2f& pos) const;

private:

	int m_rows;
	int m_cols;
	sf::Vector2f m_sizeWindow;
	sf::Vector2f m_sizeTile;
	std::vector<std::vector<std::unique_ptr<Tile>>> m_boardTile;

};

#pragma once
#include <SFML/Graphics.hpp>
#include "GameConsts.h"
#include "vector"

class GameBoard {

public:
	GameBoard();

	void initBoard(const sf::Vector2f& sizeWindow);

	int getRows() const { return m_rows; }
	int getCols() const { return m_cols; }

	bool isFrameTile(int row, int col) const; // בודקת האם האריח במסגרת
	sf::Vector2f getTileLocation(int rows, int cols) const; // מקבלת אינדקס ומחזירה את המיקום האריחי העליון שלו

private:

	int m_rows;
	int m_cols;
	sf::Vector2f m_sizeTile;
	std::vector < std::vector<sf::Vector2f>> m_boardIndex;

};

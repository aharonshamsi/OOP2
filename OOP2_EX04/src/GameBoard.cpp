#include "GameBoard.h"
#include "iostream"
GameBoard::GameBoard()
	:m_sizeTile(GameConsts::sizeTile)
{}

void GameBoard::initBoard(const sf::Vector2f& sizeWindow)
{
	m_rows = static_cast<int>((sizeWindow.y - GameConsts::HIGHT_SHAPE_INFO) / m_sizeTile.y);
	m_cols = static_cast<int>(sizeWindow.x / m_sizeTile.x);

	m_boardIndex.clear();
	m_boardIndex.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			m_boardIndex[i].push_back(sf::Vector2f(j * m_sizeTile.x, i * m_sizeTile.y));
	std::cout << m_rows << " " << m_cols;
	//std::cout << m_boardIndex[49][49].x << "  " << m_boardIndex[49][49].y;
}

bool GameBoard::isFrameTile(int row, int col) const
{
	return row == 0 || col == 0 ||
		row == m_rows - 1 || col == m_cols - 1;
}

sf::Vector2f GameBoard::getTileLocation(int row, int col) const
{
	if (row < 0 || col < 0 || row >= m_rows || col >= m_cols)
		return sf::Vector2f(0.f, 0.f); // חריגה

	return sf::Vector2f(col * m_sizeTile.x, row * m_sizeTile.y);
}



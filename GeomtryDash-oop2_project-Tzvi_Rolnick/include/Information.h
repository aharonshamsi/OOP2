#pragma once
#include <SFML/Graphics.hpp>

class Information
{
public:
	Information();
	void draw(sf::RenderWindow&);
	//-- set function --
	void setNumLevel(int level) { m_numLevel = level; }
	//-- get function --
	int getNumLevel() const {return m_numLevel; }
private:
	int m_numLevel;
};

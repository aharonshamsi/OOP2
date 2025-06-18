#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"

class Info
{
public:
	Info();
	void draw(sf::RenderWindow&);

	//-- set function --
	void setNumLevel(int level) { m_numLevel = level; }
	//void setTypePlayer(TypeObject type) { m_typePlayer = type; }

	//-- get function --
	int getNumLevel() const {return m_numLevel; }
	TypeObject getTypePlayer() const { return m_typePlayer; }

	bool buyPlayer(TypeObject type);
	bool buyPlayer(TypeObject type,int price);

private:
	int m_numLevel;
	TypeObject m_typePlayer = TypeObject::player;
	int m_money = 0; // money of the player

};

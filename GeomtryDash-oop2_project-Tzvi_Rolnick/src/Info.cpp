#include "Info.h"
#include <iostream>


Info::Info() :m_numLevel {1}
{}

void Info::draw(sf::RenderWindow& window)
{

	//...
}

bool Info::buyPlayer(TypeObject type)
{
	m_typePlayer = type;
	return true;

	//if (/*Check many*/) {
	//	m_typePlayer = type;
	//	return true;
	//}
	//return false;

}

bool Info::buyPlayer(TypeObject type, int price)
{
	if (m_money >= price) {
		m_typePlayer = type;
		m_money -= price;
		return true;
	}
	return false;
}


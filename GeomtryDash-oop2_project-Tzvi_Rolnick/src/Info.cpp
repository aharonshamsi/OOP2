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


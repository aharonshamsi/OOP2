#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
#include "vector"



class ImagesObject {
public:

	static void loadAllTextures();
	static sf::Sprite getSpinte(const TypeObject& type, const sf::Vector2f wantedSize);

private:
	
	static std::vector<sf::Texture> m_pictures;
	//
	//static void loadPlayer();
	//static void loadSmartEnemy();
	//static void loadStupidEnemy();

};


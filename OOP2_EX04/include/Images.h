#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "GameException.h"
#include "vector"

class Images
{

public:
	static void loadAllTextures();
	static sf::Sprite getSprite(const ObjectType& type, const sf::Vector2f& wantedSize);

private:
	static std::vector<sf::Texture> m_pictures;

	static void loadPlayer();
	static void loadEnemy();
};

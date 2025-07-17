#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "GameException.h"
#include "vector"

class Images {

public:
	static void loadAllTextures();
	static sf::Sprite getSprite(const ObjectType& type, const sf::Vector2f& wantedSize);
	static const sf::Texture& getTexture(ObjectType type);

private:
	static std::vector<sf::Texture> m_pictures;
	static std::vector<sf::Texture> m_textures;
	
	static void loadTextures();
	static void loadPlayer();
	static void loadEnemy();
	static void empty();
	static void filled();
};

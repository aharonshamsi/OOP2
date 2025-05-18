#include "Images.h"

std::vector <sf::Texture> Images::m_pictures;

void Images::loadAllTextures()
{
	loadPlayer();
	loadEnemy();
}

sf::Sprite Images::getSprite(const ObjectType& type, const sf::Vector2f& wantedSize)
{
	int index = static_cast<int>(type);

	sf::Sprite sprite;
	sprite.setTexture(m_pictures[index]); // טעינה תמונה 
	// נתאים את גודל התמונה 
	float scaleX = wantedSize.x / m_pictures[index].getSize().x; 
	float scaleY = wantedSize.y / m_pictures[index].getSize().y;
	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	return sprite;
}

void Images::loadPlayer()
{
	if (!m_pictures.emplace_back().loadFromFile("player.png"))
		throw GameException("Error: \n    Failed to load player image (file not found).");
}

void Images::loadEnemy()
{
	if (!m_pictures.emplace_back().loadFromFile("enemy.png"))
		throw GameException("Error: \n    Failed to load enemy image(file not found).");
}


#include "Images.h"

std::vector <sf::Texture> Images::m_pictures;
std::vector<sf::Texture> Images::m_textures;

void Images::loadAllTextures()
{
	loadTextures();
	loadPlayer();
	loadEnemy();
	empty();
	filled();
}


sf::Sprite Images::getSprite(const ObjectType& type, const sf::Vector2f& wantedSize)
{
	int index = static_cast<int>(type);

	sf::Sprite sprite;
	sprite.setTexture(m_pictures[index]); 
	float scaleX = wantedSize.x / m_pictures[index].getSize().x; 
	float scaleY = wantedSize.y / m_pictures[index].getSize().y;
	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	return sprite;
}


void Images::loadTextures() {

	m_textures.resize(static_cast<int>(ObjectType::Count));
	m_textures[static_cast<int>(ObjectType::Empty)].loadFromFile("empty.png");
	m_textures[static_cast<int>(ObjectType::Filled)].loadFromFile("filled.png");
	m_textures[static_cast<int>(ObjectType::Frame)].loadFromFile("frame.png");
	m_textures[static_cast<int>(ObjectType::Trail)].loadFromFile("trail.png");
}

const sf::Texture& Images::getTexture(ObjectType type) {
	return m_textures[static_cast<int>(type)];
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

void Images::empty()
{
	if (!m_pictures.emplace_back().loadFromFile("empty.png"))
		throw GameException("Error: \n    Failed to load enemy image(file not found).");
}


void Images::filled()
{
	if (!m_pictures.emplace_back().loadFromFile("filled.png"))
		throw GameException("Error: \n    Failed to load enemy image(file not found).");
}

#include "GameObject/Images/ImagesObject.h"


std::vector<sf::Texture>ImagesObject::m_pictures;



void ImagesObject::loadAllTextures()
{
	// הקצאה קבועה כגודל האובייקים
	m_pictures.resize(static_cast<int>(TypeObject::count)); 

	//loadPlayer();
	//loadSmartEnemy();
	//loadStupidEnemy();
}


//void ImagesObject::loadPlayer()
//{
//	if (!m_pictures[static_cast<int>(TypeObject::player)].loadFromFile("Player.png"))
//		std::cout << "Error: \n    Failed to load player image (file not found).";
//}
//
//void ImagesObject::loadSmartEnemy()
//{
//	if(!m_pictures[static_cast<int>(TypeObject::SmartEnemy)].loadFromFile("SmartEnemy.png"))
//		std::cout << "Error: \n    Failed to load smart enemy image (file not found).";
//}
//
//void ImagesObject::loadStupidEnemy()
//{
//	if(!m_pictures[static_cast<int>(TypeObject::StupidEnemy)].loadFromFile("StupidEnemy.png"))
//		std::cout << "Error: \n    Failed to load Stupid Enemy image (file not found).";
//}


sf::Sprite ImagesObject::getSpinte(const TypeObject& type, const sf::Vector2f wantedSize)
{
	int index = static_cast<int> (type);

	sf::Sprite sprint;
	sprint.setTexture(m_pictures[index]);

	int scaleX = wantedSize.x / m_pictures[index].getSize().x;
	int scaleY = wantedSize.y / m_pictures[index].getSize().y;
	sprint.setScale(scaleX, scaleY);

	return sprint;
}

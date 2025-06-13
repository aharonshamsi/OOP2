#include "ImageMenu.h"

std::vector<sf::Texture> ImageMenu::m_pictures;

void ImageMenu::loadAllTextures()
{
	m_pictures.resize(static_cast<int>(GameObjectType::count));

	loadStart();
	loadStore();
	loadHelp();
	loadExit();
	loadWatch();
	loadGitHub();

	loadDone();
	loadCancel();
	//loadplayerOne();
}

sf::Sprite ImageMenu::getSpinte(const GameObjectType& type, const sf::Vector2f& wantedSize)
{
	int index = static_cast<int>(type);

	sf::Sprite sprite;
	sprite.setTexture(m_pictures[index]);

	float scaleX = wantedSize.x / m_pictures[index].getSize().x;
	float scaleY = wantedSize.y / m_pictures[index].getSize().y;
	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	return sprite;
}

void ImageMenu::loadStart()
{
	if(!m_pictures[static_cast<int>(GameObjectType::Start)].loadFromFile("Start.png"))
		std::cout << "Error: \n    Failed to load Start button image (file not found).";
}

void ImageMenu::loadStore()
{
	if (!m_pictures[static_cast<int>(GameObjectType::Store)].loadFromFile("Store.png"))
		std::cout << "Error: \n    Failed to load Store button image (file not found).";
}

void ImageMenu::loadHelp()
{
	if(!m_pictures[static_cast<int>(GameObjectType::Help)].loadFromFile("Help.png"))
		std::cout << "Error: \n    Failed to load Help button image (file not found).";
}

void ImageMenu::loadExit()
{
	if (!m_pictures[static_cast<int>(GameObjectType::Exit)].loadFromFile("Exit.png"))
		std::cout << "Error: \n    Failed to load Exit button image (file not found).";
}

void ImageMenu::loadWatch()
{
	if (!m_pictures[static_cast<int>(GameObjectType::Watch)].loadFromFile("Watch.png"))
		std::cout << "Error: \n    Failed to load Watch button image (file not found).";
}

void ImageMenu::loadGitHub()
{
	if (!m_pictures[static_cast<int>(GameObjectType::GitHub)].loadFromFile("GitHub.png"))
		std::cout << "Error: \n    Failed to load GitHub button image (file not found).";
}

void ImageMenu::loadDone()
{
	if (!m_pictures[static_cast<int>(GameObjectType::Done)].loadFromFile("Done.png"))
		std::cout << "Error: \n    Failed to load Done button image (file not found).";
}

void ImageMenu::loadCancel()
{
	if (!m_pictures[static_cast<int>(GameObjectType::Cancel)].loadFromFile("Cancel.png"))
		std::cout << "Error: \n    Failed to load Cancel button image (file not found).";
}

//void ImageMenu::loadSpriteSheet()
//{
//	if (!m_pictures[static_cast<int>(GameObjectType::SpriteSheet)].loadFromFile("GeometryDashSpriteSheet.png"))
//		std::cout << "Error: \n    Failed to load Geometry Dash Sprite Sheet image (file not found).";
//}



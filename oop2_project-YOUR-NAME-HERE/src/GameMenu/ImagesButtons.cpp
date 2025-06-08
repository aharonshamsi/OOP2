#include "GameMenu/ImagesButtons.h"

std::vector<sf::Texture> ImagesButton::m_pictures;

void ImagesButton::loadAllTextures()
{
	m_pictures.resize(static_cast<int>(TypeButton::count));

	loadStart();
	loadStore();
	loadHelp();
	loadExit();
	loadWatch();
	loadGitHub();
}

sf::Sprite ImagesButton::getSpinte(const TypeButton& type, const sf::Vector2f& wantedSize)
{
	int index = static_cast<int>(type);

	sf::Sprite sprite;
	sprite.setTexture(m_pictures[index]);

	float scaleX = wantedSize.x / m_pictures[index].getSize().x;
	float scaleY = wantedSize.y / m_pictures[index].getSize().y;
	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	return sprite;
}

void ImagesButton::loadStart()
{
	if(!m_pictures[static_cast<int>(TypeButton::Start)].loadFromFile("Start.png"))
		std::cout << "Error: \n    Failed to load Start button image (file not found).";
}

void ImagesButton::loadStore()
{
	if (!m_pictures[static_cast<int>(TypeButton::Store)].loadFromFile("Store.png"))
		std::cout << "Error: \n    Failed to load Store button image (file not found).";
}

void ImagesButton::loadHelp()
{
	if(!m_pictures[static_cast<int>(TypeButton::Help)].loadFromFile("Help.png"))
		std::cout << "Error: \n    Failed to load Help button image (file not found).";
}

void ImagesButton::loadExit()
{
	if (!m_pictures[static_cast<int>(TypeButton::Exit)].loadFromFile("Exit.png"))
		std::cout << "Error: \n    Failed to load Exit button image (file not found).";
}

void ImagesButton::loadWatch()
{
	if (!m_pictures[static_cast<int>(TypeButton::Watch)].loadFromFile("Watch.png"))
		std::cout << "Error: \n    Failed to load Watch button image (file not found).";
}

void ImagesButton::loadGitHub()
{
	if (!m_pictures[static_cast<int>(TypeButton::GitHub)].loadFromFile("GitHub.png"))
		std::cout << "Error: \n    Failed to load GitHub button image (file not found).";
}

#include "GameMenu/Background.h"

Background::Background(const std::string nameFile)
{
	if (!m_texture.loadFromFile(nameFile))
		std::cout << "Error: \n    Failed to load Background" + nameFile + "image(file not found).";

	m_sprint.setTexture(m_texture);
	m_sprint.setPosition(0, 0);

	sf::Vector2f sizePictur(
		GameData::SIZE_GAME_WINDOW.x,
		GameData::SIZE_GAME_WINDOW.y
	);

	m_sprint.setScale(
		sizePictur.x / m_texture.getSize().x,
		sizePictur.y / m_texture.getSize().y
	);

}


void Background::draw(sf::RenderWindow& window)
{
	sf::Vector2f topLeft = window.mapPixelToCoords({ 0, 0 });
	m_sprint.setPosition(topLeft);
	window.draw(m_sprint);//m_sprite
}

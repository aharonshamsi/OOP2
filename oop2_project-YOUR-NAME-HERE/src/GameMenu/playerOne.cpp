#include "GameMenu/playerOne.h"

PlayerOne::PlayerOne(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(GameObjectType::playerOne, location, wantedSize)
{
	m_sprite = m_sprite = ImagesObject::getSpinte(GameObjectType::playerOne, wantedSize);
}

void PlayerOne::handleClick(State& state, sf::RenderWindow& window, sf::Event& event)
{
	std::cout << "FF";
	// נעדכן את info לtype
}

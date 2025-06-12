#include "GameMenu/Start.h"

Start::Start(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Start, wantedSize);
}

MenuAction Start::handleClick(Info& info, sf::RenderWindow& window)
{
	return MenuAction::StartLevel;
}

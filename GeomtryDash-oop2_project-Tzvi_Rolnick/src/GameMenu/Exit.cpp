#include "GameMenu/Exit.h"

Exit::Exit(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Exit, wantedSize);
}

MenuAction Exit::handleClick(Info& info, sf::RenderWindow& window)
{
	return MenuAction::ExitGame;
}


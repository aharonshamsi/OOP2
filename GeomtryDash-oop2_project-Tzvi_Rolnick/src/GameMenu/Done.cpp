#include "GameMenu/Done.h"

Done::Done(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Done, wantedSize);
}

MenuAction Done::handleClick(Info& info, sf::RenderWindow& window)
{
	return MenuAction::Done;
}

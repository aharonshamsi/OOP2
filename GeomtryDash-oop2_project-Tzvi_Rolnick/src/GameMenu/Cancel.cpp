#include "GameMenu/Cancel.h"

Cancel::Cancel(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Cancel, wantedSize);
}

MenuAction Cancel::handleClick(Info& info, sf::RenderWindow& window)
{
	return MenuAction::Cancel;
}

#include "GameMenu/playerOne.h"

PlayerOne::PlayerOne(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = m_sprite = ImageMenu::getSpinte(GameObjectType::playerOne, wantedSize);
}

MenuAction PlayerOne::handleClick(Info& info, sf::RenderWindow& window)
{
	////info.setNumLevel(1); // need to change
	//info.setTypePlayer(TypeObject::PlayerOne);

	return MenuAction::None;
}


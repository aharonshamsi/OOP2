#include "GameMenu/playerOne.h"

PlayerOne::PlayerOne(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
    : CharactersButton(location, wantedSize)
{
    m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerOne);
	scaleCharacters(wantedSize);
}


MenuAction PlayerOne::handleClick(Info& info, sf::RenderWindow& window)
{
	////info.setNumLevel(1); // need to change
	if (info.buyPlayer(TypeObject::PlayerOne))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}


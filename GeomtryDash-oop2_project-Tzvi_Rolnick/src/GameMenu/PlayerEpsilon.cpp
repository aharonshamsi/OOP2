#include "GameMenu/PlayerEpsilon.h"

PlayerEpsilon::PlayerEpsilon(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerEpsilon);
	scaleCharacters(wantedSize);
}

MenuAction PlayerEpsilon::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerEpsilon))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}
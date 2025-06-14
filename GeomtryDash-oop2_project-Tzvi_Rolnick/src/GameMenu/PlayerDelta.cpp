#include "GameMenu/PlayerDelta.h"

PlayerDelta::PlayerDelta(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerDelta);
	scaleCharacters(wantedSize);
}

MenuAction PlayerDelta::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerDelta))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}
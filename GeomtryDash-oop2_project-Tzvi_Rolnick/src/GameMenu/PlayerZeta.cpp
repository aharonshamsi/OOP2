#include "GameMenu/PlayerZeta.h"

PlayerZeta::PlayerZeta(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerZeta);
	scaleCharacters(wantedSize);
}

MenuAction PlayerZeta::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerZeta))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}
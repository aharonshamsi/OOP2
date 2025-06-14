#include "GameMenu/PlayerGamma.h"

PlayerGamma::PlayerGamma(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerGamma);
	scaleCharacters(wantedSize);
}

MenuAction PlayerGamma::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerGamma))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}

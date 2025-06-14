#include "GameMenu/PlayerAlpha.h"

PlayerAlpha::PlayerAlpha(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
    : CharactersButton(location, wantedSize)
{
    m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayeraAlpha);
	scaleCharacters(wantedSize);
}


MenuAction PlayerAlpha::handleClick(Info& info, sf::RenderWindow& window)
{
	////info.setNumLevel(1); // need to change
	if (info.buyPlayer(TypeObject::PlayeraAlpha))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}


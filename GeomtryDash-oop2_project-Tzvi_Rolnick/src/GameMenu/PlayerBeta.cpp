#include "GameMenu/PlayerBeta.h"

PlayerBeta::PlayerBeta(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	: CharactersButton(location, wantedSize)
{
	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayeraBeta);
	scaleCharacters(wantedSize);
}

MenuAction PlayerBeta::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayeraBeta))
		std::cout << "buy cecssek\n";

	return MenuAction::None;
}

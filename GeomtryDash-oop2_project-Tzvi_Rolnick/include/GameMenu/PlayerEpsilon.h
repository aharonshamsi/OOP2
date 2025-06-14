#pragma once
#include "CharactersButton.h"

class PlayerEpsilon : public CharactersButton {

public:
	PlayerEpsilon(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;
};

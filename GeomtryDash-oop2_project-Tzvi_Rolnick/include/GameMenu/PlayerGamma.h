#pragma once
#include "CharactersButton.h"

class PlayerGamma : public CharactersButton {

public:
	PlayerGamma(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;
};

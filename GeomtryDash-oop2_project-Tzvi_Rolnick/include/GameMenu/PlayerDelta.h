#pragma once
#include "CharactersButton.h"

class PlayerDelta : public CharactersButton {

public:
	PlayerDelta(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;
};

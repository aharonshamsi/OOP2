#pragma once
#include "CharactersButton.h"

class PlayerZeta : public CharactersButton {

public:
	PlayerZeta(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;
};

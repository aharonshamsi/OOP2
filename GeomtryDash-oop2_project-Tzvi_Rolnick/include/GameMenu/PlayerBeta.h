#pragma once
#include "CharactersButton.h"


class PlayerBeta : public CharactersButton {

public:
	PlayerBeta(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

};

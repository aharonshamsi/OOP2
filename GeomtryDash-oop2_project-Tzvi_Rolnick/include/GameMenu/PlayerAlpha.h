#pragma once
#include "GameMenu/CharactersButton.h"



class PlayerAlpha : public CharactersButton {

public:
	PlayerAlpha(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

};
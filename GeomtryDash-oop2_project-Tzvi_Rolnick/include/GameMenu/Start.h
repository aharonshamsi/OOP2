#pragma once
#include "GameMenu/Button.h"

class Start : public Button {

public:
	Start(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;
};
#pragma once
#include "GameMenu/Button.h"

class Exit : public Button {

public:
	Exit(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;
};

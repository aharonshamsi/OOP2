#pragma once
#include "Button.h"

class Done : public Button {

public:
	Done(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

};
#pragma once
#include "Button.h"


class Cancel : public Button {

public:
	Cancel(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

};

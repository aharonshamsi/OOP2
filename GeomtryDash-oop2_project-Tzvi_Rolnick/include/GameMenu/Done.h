#pragma once
#include "Button.h"

class Done : public Button {

public:
	Done(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) override;
};
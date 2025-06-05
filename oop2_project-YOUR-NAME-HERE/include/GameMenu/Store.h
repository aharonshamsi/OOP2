#pragma once
#include "GameMenu/Button.h"

class Store : public Button {

public:
	Store(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) override;

private:

};

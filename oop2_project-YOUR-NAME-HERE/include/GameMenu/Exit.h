#pragma once
#pragma once
#include "GameMenu/Button.h"

class Exit : public Button {

public:
	Exit(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) override;
};

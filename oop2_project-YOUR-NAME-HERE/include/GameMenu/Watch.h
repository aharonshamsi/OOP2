#pragma once
#include "Button.h"

class Watch : public Button {

public:
	Watch (const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) override;

private:
	std::string m_url; // קישור לסרטון
};

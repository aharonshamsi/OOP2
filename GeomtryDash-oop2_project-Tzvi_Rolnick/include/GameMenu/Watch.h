#pragma once
#include "Button.h"

class Watch : public Button {

public:
	Watch (const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

private:
	std::string m_url; // Address Link 
};

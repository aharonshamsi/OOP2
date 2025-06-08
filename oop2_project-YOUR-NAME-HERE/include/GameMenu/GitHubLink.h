#pragma once
#include "Button.h"

class GitHubLink : public Button {

public:
	GitHubLink(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) override;

private:
	std::string m_url; //  קישור git שם

};
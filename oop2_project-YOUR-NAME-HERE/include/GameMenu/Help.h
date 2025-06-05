#pragma once
#include "GameMenu/Button.h"
#include "FontHolder.h"

class Help : public Button {

public:
	Help(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) override;

private:
	sf::Text m_instructionText; 
	std::string m_instructions;
	
	void InitInstructions();
};
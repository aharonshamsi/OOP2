#pragma once
#include "Button.h"
#include "FontHolder.h"

class Help : public Button {

public:
	Help(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

private:
	sf::Text m_instructionText; 
	std::string m_instructions;
	
	void InitInstructions();
};
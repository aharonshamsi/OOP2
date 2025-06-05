#include "GameMenu/Exit.h"

Exit::Exit(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::Exit, location, wantedSize)
{}

void Exit::handleClick(State & state, sf::RenderWindow& window, sf::Event& event)
{
	state.setExit(true);
}


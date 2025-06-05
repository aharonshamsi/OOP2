#include "GameMenu/Start.h"

Start::Start(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::Start, location, wantedSize)
{}


void Start::handleClick(State& state, sf::RenderWindow& window, sf::Event& event)
{
	state.setStart(true); 
}

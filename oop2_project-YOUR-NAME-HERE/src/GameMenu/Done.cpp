#include "GameMenu/Done.h"

Done::Done(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(GameObjectType::Done, location, wantedSize)
{
}

void Done::handleClick(State& state, sf::RenderWindow& window, sf::Event& event)
{
	state.setDoneButton(true);
}

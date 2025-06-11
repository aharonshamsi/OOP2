#include "GameMenu/Done.h"

Done::Done(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Done, wantedSize);
}

void Done::handleClick(State& state, sf::RenderWindow& window, sf::Event& event)
{
	state.setDoneButton(true);
}

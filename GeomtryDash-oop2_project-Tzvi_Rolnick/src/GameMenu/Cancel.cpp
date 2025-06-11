#include "GameMenu/Cancel.h"

Cancel::Cancel(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Cancel, wantedSize);
}

void Cancel::handleClick(State& state, sf::RenderWindow& window, sf::Event& event)
{
	state.setCancelButton(true);
}

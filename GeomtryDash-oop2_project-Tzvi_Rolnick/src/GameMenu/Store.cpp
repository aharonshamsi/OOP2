#include "GameMenu/Store.h"

Store::Store(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Store, wantedSize);
}

void Store::handleClick(State & state, sf::RenderWindow& window, sf::Event& event)
{
	state.setStore(true);
	m_gameStore.runStore(window, state, event /*,info*/); // Open Store
}

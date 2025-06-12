#include "GameMenu/Store.h"

Store::Store(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
:Button(location)
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Store, wantedSize);
}

MenuAction Store::handleClick(Info& info, sf::RenderWindow& window)
{
    m_gameStore.runStore(info, window); 
    return MenuAction::None;
}

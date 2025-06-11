#include "GameMenu/Watch.h"
#include <windows.h>


Watch::Watch(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location),
	m_url("https://www.youtube.com/watch?v=YOUR_VIDEO_ID")
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::Watch, wantedSize);
}


void Watch::handleClick(State & state, sf::RenderWindow & window, sf::Event & event)
{
	state.setWatch(true);
	ShellExecuteA(nullptr, "open", m_url.c_str(), nullptr, nullptr, SW_SHOWNORMAL); // Open link
}

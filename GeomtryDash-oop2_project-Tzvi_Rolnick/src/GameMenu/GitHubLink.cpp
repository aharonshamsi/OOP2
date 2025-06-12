#include "GameMenu/GitHubLink.h"
#include <windows.h>

GitHubLink::GitHubLink(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location),
	m_url("https://github.com/aharonshamsi")
{
	m_sprite = ImageMenu::getSpinte(GameObjectType::GitHub, wantedSize);
}

MenuAction GitHubLink::handleClick(Info& info, sf::RenderWindow& window)
{
	ShellExecuteA(nullptr, "open", m_url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
	return MenuAction::None;
}

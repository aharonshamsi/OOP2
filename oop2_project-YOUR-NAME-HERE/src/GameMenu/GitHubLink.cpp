#include "GameMenu/GitHubLink.h"
#include <windows.h>

GitHubLink::GitHubLink(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::GitHub, location, wantedSize),
	m_url("https://github.com/aharonshamsi") // קישור  של סירטון של המחשק
{}

void GitHubLink::handleClick(State & state, sf::RenderWindow & window, sf::Event & event)
{
	state.setGitHub(true);

	//std::string command = "start " + m_url; // Windows
	//system(command.c_str()); 

	ShellExecuteA(nullptr, "open", m_url.c_str(), nullptr, nullptr, SW_SHOWNORMAL); // פקודת מערכת לפתיחת הקישור
}

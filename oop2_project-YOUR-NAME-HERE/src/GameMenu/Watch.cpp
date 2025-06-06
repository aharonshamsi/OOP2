#include "GameMenu/Watch.h"
#include <windows.h>


Watch::Watch(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::Watch, location, wantedSize),
	m_url("https://www.youtube.com/watch?v=YOUR_VIDEO_ID") // קישור  של סירטון של המחשק
{}

void Watch::handleClick(State & state, sf::RenderWindow & window, sf::Event & event)
{
	state.setWatch(true);

	//std::string command = "start " + m_url; // Windows
	//system(command.c_str()); 

	ShellExecuteA(nullptr, "open", m_url.c_str(), nullptr, nullptr, SW_SHOWNORMAL); // פקודת מערכת לפתיחת הסירטון
}

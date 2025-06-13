#pragma once
#include "Button.h"
#include "vector"


#include "Background.h"
#include "Start.h"
#include "Exit.h"
#include "Help.h"
#include "Store.h"
#include "Watch.h"
#include "GitHubLink.h"


class MenuManager {

public:
	MenuManager();

	MenuAction runMenu(Info& info, sf::RenderWindow& window);

private:
	Background m_backgroundMenu;
	std::vector<std::unique_ptr<Button>> m_button;
	
	void drawMenu(sf::RenderWindow& window);
	MenuAction clickManager(sf::RenderWindow& window, Info& info);
};
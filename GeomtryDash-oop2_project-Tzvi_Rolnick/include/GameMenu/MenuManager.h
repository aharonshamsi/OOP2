#pragma once
#include "Button.h"
#include "vector"

#include "MenuInfo.h"


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


	void runMenu(MenuInfo& info, sf::RenderWindow& window);
	bool needToStart() const; 
	bool needToExit() const;

private:

	Background m_backgroundMenu; // תמונה רקע של התפריט
	std::vector<std::unique_ptr<Button>> m_button;

	State m_stateButton;
	
	void handleButtonClick(sf::RenderWindow& window, const sf::Vector2f& mousePos, sf::Event& event); // בודקת אם כפתור נחלץ ומפעילה את התנהגות הכפתור
	void drawMenu(sf::RenderWindow& window);
	void clickManager(sf::RenderWindow& window);
};
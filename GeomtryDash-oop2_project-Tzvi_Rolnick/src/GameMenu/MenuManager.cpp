#include "GameMenu/MenuManager.h"

MenuManager::MenuManager()
	:m_backgroundMenu("Background.png")
{
	m_button.push_back(std::make_unique<Start>(ButtonData::LOC_START, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Exit>(ButtonData::LOC_EXIT, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Help>(ButtonData::LOC_HELP, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Store>(ButtonData::LOC_STORE, ButtonData::SIZE_BUTTON));

	m_button.push_back(std::make_unique<Watch>(ButtonData::LOC_WATCH, ButtonData::SIZE_ICON_BUTTON));
	m_button.push_back(std::make_unique<GitHubLink>(ButtonData::LOC_GIT_HUB, ButtonData::SIZE_ICON_BUTTON));
}

void MenuManager::handleButtonClick(sf::RenderWindow& window, const sf::Vector2f& mousePos, sf::Event& event)
{
	for (int i = 0; i < m_button.size(); i++) {
		if (m_button[i]->isPressed(mousePos))
			m_button[i]->handleClick(m_stateButton, window, event);
	}
}


void MenuManager::runMenu(MenuInfo& info, sf::RenderWindow& window)
{
	m_stateButton.initStates();

	while (!needToStart() && !needToExit()){
		window.clear();
		m_backgroundMenu.draw(window);
		drawMenu(window);
		clickManager(window);
		window.display();
	}
}


bool MenuManager::needToStart() const
{
	return m_stateButton.isStart();
}

bool MenuManager::needToExit() const{
	return m_stateButton.isExit();
}


void MenuManager::drawMenu(sf::RenderWindow& window)
{

	for (int i = 0; i < m_button.size(); i++)
		m_button[i]->draw(window);

}


void MenuManager::clickManager(sf::RenderWindow& window)
{
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2f mousePos = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

			handleButtonClick(window, mousePos, event);
		}
	}
}

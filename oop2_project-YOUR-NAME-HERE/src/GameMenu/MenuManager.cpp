#include "GameMenu/MenuManager.h"

MenuManager::MenuManager(sf::RenderWindow& window)
	:m_window(window), m_backgroundMenu("Background.png")
{
	m_button.push_back(std::make_unique<Start>(ButtonData::LOC_START, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Exit>(ButtonData::LOC_EXIT, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Help>(ButtonData::LOC_HELP, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Store>(ButtonData::LOC_STORE, ButtonData::SIZE_BUTTON));

	m_button.push_back(std::make_unique<Watch>(ButtonData::LOC_WATCH, ButtonData::SIZE_ICON_BUTTON));
	m_button.push_back(std::make_unique<GitHubLink>(ButtonData::LOC_GIT_HUB, ButtonData::SIZE_ICON_BUTTON));
}

void MenuManager::handleButtonClick(const sf::Vector2f& mousePos, sf::Event& event)
{
	for (int i = 0; i < m_button.size(); i++) {
		if (m_button[i]->isPressed(mousePos))
			m_button[i]->handleClick(m_stateButton, m_window, event);
	}
}


void MenuManager::runMenu(sf::Event& event)
{
	m_stateButton.initStates();

	while (!handleStart() && !handleExit()){
		m_window.clear();
		m_backgroundMenu.draw(m_window);
		drawMenu();
		clickManager(event);
		m_window.display();
	}
}


bool MenuManager::handleStart() const
{
	return m_stateButton.isStart();
}

bool MenuManager::handleExit() const{
	return m_stateButton.isExit();
}


void MenuManager::drawMenu()
{

	for (int i = 0; i < m_button.size(); i++)
		m_button[i]->draw(m_window);

}


void MenuManager::clickManager(sf::Event& event)
{
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2f mousePos = m_window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

			handleButtonClick(mousePos, event);
		}
	}
}

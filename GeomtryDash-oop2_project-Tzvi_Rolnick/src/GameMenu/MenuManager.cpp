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


MenuAction MenuManager::runMenu(Info& info, sf::RenderWindow& window)
{
	while (true) {
		window.clear();
		m_backgroundMenu.draw(window);
		drawMenu(window);
		MenuAction result = clickManager(window, info);
		window.display();

		if (result != MenuAction::None)
			return result;
	}
}


MenuAction MenuManager::clickManager(sf::RenderWindow& window, Info& info)
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2f mousePos = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

			for (auto& button : m_button) {
				if (button->isPressed(mousePos)) {
					return button->handleClick(info, window);
				}
			}
		}
	}
	return MenuAction::None;
}



void MenuManager::drawMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < m_button.size(); i++)
		m_button[i]->draw(window);
}


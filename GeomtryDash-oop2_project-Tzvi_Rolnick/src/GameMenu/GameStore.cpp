#include "GameMenu/GameStore.h"

GameStore::GameStore()
	:m_backgroundStore("BackgroundStore.png"), m_runStore(false)
{
    m_character.emplace_back(CharacterOption{
        std::make_unique<PlayerOne>(ButtonData::LOC_START, ButtonData::SIZE_BUTTON),
        false
        });

	m_buttonStore.push_back(std::make_unique<Done>(ButtonData::LOC_DONE, ButtonData::SIZE_ICON_BUTTON));
	m_buttonStore.push_back(std::make_unique<Cancel>(ButtonData::LOC_CANCEL, ButtonData::SIZE_ICON_BUTTON));
}

void GameStore::runStore(Info& info, sf::RenderWindow& window)
{
	m_runStore = true;

	while (m_runStore) { 
		window.clear();
		m_backgroundStore.draw(window);
		drawStore(window);
		clickManager(info, window);
		window.display();
	}
}



void GameStore::clickManager(Info& info, sf::RenderWindow& window)
{
	sf::Event event;
	sf::Vector2f mousePos;
	MenuAction action = MenuAction::None;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			mousePos = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

			for (int i = 0; i < m_character.size(); i++) {
				if (m_character[i].button->isPressed(mousePos)) {
					action = m_character[i].button->handleClick(info, window);
					m_character[i].acquired = true;
				}
			}

			for (int i = 0; i < m_buttonStore.size(); i++) {
				if (m_buttonStore[i]->isPressed(mousePos))
					action = m_buttonStore[i]->handleClick(info, window);
			}

		}
		if(action == MenuAction::Done || action == MenuAction::Cancel)
			m_runStore = false;
	}
}


void GameStore::drawStore(sf::RenderWindow& window)
{
	for (int i = 0; i < m_character.size(); i++)
		m_character[i].button->draw(window);

	for (int i = 0; i < m_buttonStore.size(); i++)
		m_buttonStore[i]->draw(window);
}

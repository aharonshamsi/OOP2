#include "GameMenu/GameStore.h"

GameStore::GameStore()
	:m_backgroundStore("BackgroundStore.png"), m_runStore(false)
{
	loadAllObjects();

	m_buttonStore.push_back(std::make_unique<Done>(ButtonData::LOC_DONE, ButtonData::SIZE_ICON_BUTTON));
	m_buttonStore.push_back(std::make_unique<Cancel>(ButtonData::LOC_CANCEL, ButtonData::SIZE_ICON_BUTTON));
}


void GameStore::loadAllObjects()
{
	m_character.emplace_back(
		std::make_unique<PlayerAlpha>(ButtonData::LOC_PAYER_ALPHA, ButtonData::SIZE_BUY_PLAYER),
		false
	);

	m_character.emplace_back(
		std::make_unique<PlayerBeta>(ButtonData::LOC_PAYER_BETA, ButtonData::SIZE_BUY_PLAYER),
		false
	);


	m_character.emplace_back(
		std::make_unique<PlayerGamma>(ButtonData::LOC_PAYER_GAMMA, ButtonData::SIZE_BUY_PLAYER),
		false
	);


	m_character.emplace_back(
		std::make_unique<PlayerDelta>(ButtonData::LOC_PAYER_DELTA, ButtonData::SIZE_BUY_PLAYER),
		false
	);

	m_character.emplace_back(
		std::make_unique<PlayerEpsilon>(ButtonData::LOC_PAYER_EPSILON, ButtonData::SIZE_BUY_PLAYER),
		false
	);

	m_character.emplace_back(
		std::make_unique<PlayerZeta>(ButtonData::LOC_PAYER_ZETA, ButtonData::SIZE_BUY_PLAYER),
		false
	);

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
				if (m_character[i].first->isPressed(mousePos)) {
					action = m_character[i].first->handleClick(info, window);
					m_character[i].second = true; // but player
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
		m_character[i].first->draw(window);

	for (int i = 0; i < m_buttonStore.size(); i++)
		m_buttonStore[i]->draw(window);
}

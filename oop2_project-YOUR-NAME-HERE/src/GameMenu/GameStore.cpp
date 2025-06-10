#include "GameMenu/GameStore.h"

GameStore::GameStore()
	:m_backgroundStore("BackgroundStore.png")
{
    m_character.emplace_back(CharacterOption{
        std::make_unique<PlayerOne>(ButtonData::LOC_START, ButtonData::SIZE_BUTTON),
        false
        });
}

void GameStore::runStore(sf::RenderWindow& window, State& state, sf::Event& event)
{

		while (m_character[0].acquired == false) { // נצרטרך לבדוק את כולם

			if (event.type == sf::Event::Closed)
				return;
			window.clear();
			// פה נדפיס רקע
			m_backgroundStore.draw(window);

			// הדפסת כפתורים חנות
			drawStore(window);
			clickManager(window, state, event);
			window.display();
		}
	
}

void GameStore::drawStore(sf::RenderWindow& window)
{
	for (int i = 0; i < m_character.size(); i++)
		m_character[i].button->draw(window);
}


void GameStore::clickManager(sf::RenderWindow& window, State& state, sf::Event& event)
{

	sf::Vector2f mousePos;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			mousePos = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

		}
		handleButtonClick(window, mousePos, event, state);
	}
}


void GameStore::handleButtonClick(sf::RenderWindow& window, sf::Vector2f& mousePos, sf::Event& event, State& state)
{
	for (int i = 0; i < m_character.size(); i++) {
		if (m_character[i].button->isPressed(mousePos)) {
			m_character[i].button->handleClick(state, window, event);
			m_character[i].acquired = true; // נעדכן שהדמות נרכשה
		}
	}
}


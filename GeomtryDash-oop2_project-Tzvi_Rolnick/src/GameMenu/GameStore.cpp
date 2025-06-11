#include "GameMenu/GameStore.h"

GameStore::GameStore()
	:m_backgroundStore("BackgroundStore.png")
{
    m_character.emplace_back(CharacterOption{
        std::make_unique<PlayerOne>(ButtonData::LOC_START, ButtonData::SIZE_BUTTON),
        false
        });

	m_buttonStore.push_back(std::make_unique<Done>(ButtonData::LOC_DONE, ButtonData::SIZE_ICON_BUTTON));
	m_buttonStore.push_back(std::make_unique<Cancel>(ButtonData::LOC_CANCEL, ButtonData::SIZE_ICON_BUTTON));
}


void GameStore::runStore(sf::RenderWindow& window, State& state, sf::Event& event)
{
		state.initStatesStore();

		while (!state.isDoneButton() && !state.isCancelButton()) { // נצרטרך לבדוק את כולם

			if (event.type == sf::Event::Closed)
				return;

			window.clear();
			m_backgroundStore.draw(window);
			drawStore(window);
			clickManagerChar(window, state, event);
			window.display();
		}
	
}

void GameStore::drawStore(sf::RenderWindow& window)
{
	for (int i = 0; i < m_character.size(); i++)
		m_character[i].button->draw(window);

	for (int i = 0; i < m_buttonStore.size(); i++)
		m_buttonStore[i]->draw(window);
}


void GameStore::clickManagerChar(sf::RenderWindow& window, State& state, sf::Event& event)
{
	sf::Vector2f mousePos;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			mousePos = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

			handleButtonClick(window, mousePos, event, state);
			clickManagerButton(mousePos, state, window, event);
		}
	}
}

void GameStore::clickManagerButton(sf::Vector2f& mousePos, State& state, sf::RenderWindow& window, sf::Event& event)
{
	for (int i = 0; i < m_buttonStore.size(); i++) {
		if (m_buttonStore[i]->isPressed(mousePos))
			m_buttonStore[i]->handleClick(state, window, event);
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


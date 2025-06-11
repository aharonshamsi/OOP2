#pragma once
#include "GameObjectType.h"
#include "Button.h"
#include "playerOne.h"
#include "Background.h"

#include "Done.h"
#include "Cancel.h"

struct CharacterOption
{
	std::unique_ptr<Button> button;
	bool acquired = false;
};


class GameStore {

public:
	GameStore();

	void runStore(sf::RenderWindow& window, State& state, sf::Event& event);

private:

	std::vector<CharacterOption> m_character;
	Background m_backgroundStore;

	std::vector<std::unique_ptr<Button>> m_buttonStore;

	void drawStore(sf::RenderWindow& window);
	void clickManagerChar(sf::RenderWindow& window, State& state, sf::Event& event);
	void clickManagerButton(sf::Vector2f& mousePos, State& state, sf::RenderWindow& window, sf::Event& event);
	void handleButtonClick(sf::RenderWindow& window, sf::Vector2f& mousePos ,sf::Event & event, State& state);

};

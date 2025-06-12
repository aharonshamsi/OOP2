#pragma once
#include "Button.h"
#include "GameStore.h"

class Store : public Button {

public:
	Store(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

private:
	GameStore m_gameStore;
};

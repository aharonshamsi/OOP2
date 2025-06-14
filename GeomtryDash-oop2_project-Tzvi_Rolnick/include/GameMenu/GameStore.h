#pragma once
#include "GameObjectType.h"
#include "Button.h"
#include "Background.h"

#include "Done.h"
#include "Cancel.h"

#include "PlayerAlpha.h"
#include "PlayerBeta.h"
#include "PlayerGamma.h"
#include "PlayerDelta.h"
#include "PlayerEpsilon.h"
#include "PlayerZeta.h"


class GameStore {

public:
	GameStore();

	void runStore(Info& info, sf::RenderWindow& window);

private:

	std::vector<std::unique_ptr<Button>> m_buttonStore;
	std::vector<std::pair<std::unique_ptr<Button>, bool>> m_character;

	Background m_backgroundStore;
	bool m_runStore;

	void drawStore(sf::RenderWindow& window);
	void clickManager(Info& info, sf::RenderWindow& window);
	void loadAllObjects();
};

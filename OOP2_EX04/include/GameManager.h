#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>

#include "GameConsts.h"
#include "GameException.h"
#include "DisplayError.h"
#include "GameInfo.h"

class GameManager {

public:
	GameManager();

	void run();

private:
	sf::RenderWindow m_gameWindow;
	sf::Vector2f m_sizeWindow;
	GameInfo m_gameInfo;

	void readLevel(std::string& nameLevel, std::string& infoLevel); // 
	void initGameInfo(std::string& infoLevel);
	void initGameWindow();
	void displayError(GameException& error); // מציגה שגיאה על החלון
};

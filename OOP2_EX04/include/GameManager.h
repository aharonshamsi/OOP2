#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>

#include "GameException.h"
#include "ErrorWindow.h"

#include "GameConsts.h"
#include "GameInfo.h"

class GameManager {

public:
	GameManager();

	void run();

private:
	sf::RenderWindow m_gameWindow;
	sf::Vector2f m_sizeWindow;
	GameInfo m_gameInfo;

	int m_neededArea; // יעד כבישה שצריך
	int m_numEnemies; // מספר האויביים

	void readLevel(std::string& nameLevel, std::string& infoLevel); // 
	void initGameInfo(std::string& infoLevel);
	void initGameWindow();
	void displayError(GameException& error); // מציגה שגיאה על החלון
};

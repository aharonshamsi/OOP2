#pragma once
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>

#include "Images.h"
#include "GameException.h"
#include "ErrorWindow.h"
#include "GameBoard.h"
#include "GameInfo.h"

#include "MovingObject.h"
#include "Player.h"
#include "Enemy.h"

class GameManager {

public:
	GameManager();

	void run();

private:
	sf::RenderWindow m_gameWindow;
	sf::Vector2f m_sizeWindow;
	GameBoard m_gameBoard;
	GameInfo m_gameInfo;

	int m_neededArea; // יעד כבישה שצריך
	int m_numEnemies; // מספר האויביים

	void readLevel(std::string& nameLevel, std::string& infoLevel); // 
	void initGameInfo(std::string& infoLevel);
	void initGameWindow();
	void displayError(GameException& error); // מציגה שגיאה על החלון
	void createObjectsFromFile(); // מכניס אובייקטים שחקן ואייבים
	void colorFrame(); //  צובע גבולות חלון
};

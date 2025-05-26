#pragma once
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>

#include "Images.h"
#include "Background.h"
#include "GameException.h"
#include "ErrorWindow.h"
#include "TileBoard.h"
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
	GameInfo m_gameInfo;
	TileBoard m_boardTiles;
	std::vector<std::unique_ptr<MovingObject>> m_objectMoving;

	int m_neededArea; 
	int m_numEnemies; 

	void initLevel(const std::string& nameLevel);
	void readLevel(const std::string& nameLevel, std::string& infoLevel);
	void initGameInfo(std::string& infoLevel);
	void initGameWindow();
	void displayError(GameException& error); 
	void createObject(); 
	void drawObjects(); 
	void restartObjectLoc();
	void drawManager();
	void drawBackground();
	void drawFinishGame();
	void drawStartBackground();
	void setAllInfo(int playerLives, float timeLevel);
	

};

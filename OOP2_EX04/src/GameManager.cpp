#include "GameManager.h"

GameManager::GameManager()
	:m_neededArea(0), m_numEnemies(0)
{}

void GameManager::run() {

	try
	{
		Images::loadAllTextures(); // Loading static images
		
		std::ifstream filePlaylist(GameConsts::NAME_FLAYLIST_LEVEL);
		if (!filePlaylist.is_open())
			throw GameException("Error: \n   Failed to open playlist file!");


		std::string nameLevel;

		while (std::getline(filePlaylist, nameLevel)) {

			initLevel(nameLevel);
			drawStartBackground();

			sf::Clock clock;
			clock.restart();

			while (m_gameWindow.isOpen() && m_gameInfo.getPlayerLives() > 0) {
				auto time = clock.restart().asSeconds(); 

				sf::Event event;
				while (m_gameWindow.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						m_gameWindow.close();
						return;
					}
				}

				// HandleCollision management
				for (int i = 0; i < m_objectMoving.size(); i++) {
					m_objectMoving[i]->move(time, m_boardTiles, m_gameInfo);

					for (int j = 0; j < m_objectMoving.size(); j++) {
						if (i != j)
							m_objectMoving[i]->handleCollision(*m_objectMoving[j], m_gameInfo);
					}
				}

				// Checking the area occupied
				if (m_gameInfo.getNeedAreaCheck()) { 
					m_boardTiles.markCapturedArea();
					m_gameInfo.setNeedAreaCheck(false);
				}

				// Player disqualified
				if (m_gameInfo.getIsViolation()) {
					restartObjectLoc(); 
					m_boardTiles.restartTrail(); 
					m_gameInfo.restartViolation();
				}

				drawManager();

				if (m_gameInfo.getCapturedPercent() >= m_neededArea)
					break;
			}
			if (m_gameInfo.getPlayerLives() <= 0) {
				drawFinishGame();
				return;
			}

			m_gameInfo.resetInfo();
		}

	}

	catch (GameException& error)
	{
		std::cout << error.what();
		displayError(error);
	}

}


void GameManager::initLevel(const std::string& nameLevel)
{
	std::string infoLevel;
	readLevel(nameLevel, infoLevel);
	initGameInfo(infoLevel);
	initGameWindow();
	m_boardTiles.initTileBoard(m_sizeWindow);
	createObject();
}

void GameManager::readLevel(const std::string& nameLevel, std::string& infoLevel)
{
	std::ifstream fileLevel(nameLevel);
	if (!fileLevel.is_open())
		throw GameException("Error: \n   Failed to open level file: " + nameLevel);
	std::getline(fileLevel, infoLevel);
}


void GameManager::initGameInfo(std::string& infoLevel)
{
	int playerLives;
	float timeLevel;

	std::istringstream lineStream(infoLevel);

	if (!(lineStream >> m_neededArea >> m_numEnemies >>
		m_sizeWindow.x >> m_sizeWindow.y >> playerLives >> timeLevel)) {
			throw GameException("Error: \n   Invalid data format in level file!");
	}

	setAllInfo(playerLives, timeLevel);
	m_gameInfo.initStatusBar(m_sizeWindow);
}


void GameManager::initGameWindow()
{
	m_gameWindow.create(sf::VideoMode(static_cast<unsigned int>(m_sizeWindow.x),
		static_cast<unsigned int>(m_sizeWindow.y)), GameConsts::NAME_GAME);
	m_gameWindow.clear();
	m_gameWindow.setFramerateLimit(60); 

}


void GameManager::createObject()
{
	m_objectMoving.clear();
	sf::Vector2f locPlayer = m_boardTiles.getTileLocByIndex(m_boardTiles.getCols() / 2, 0);
	m_objectMoving.push_back(std::make_unique<Player>(locPlayer, m_boardTiles.getSizeTile()));

	for (int i = 0; i < m_numEnemies; i++) {
		sf::Vector2f locEnemy = m_boardTiles.randLocation();
		m_boardTiles.getTileLoc(locEnemy);
		m_objectMoving.push_back(std::make_unique<Enemy>(locEnemy, m_boardTiles.getSizeTile()));
	}

}

void GameManager::drawObjects()
{
	for (const auto& object : m_objectMoving)
		object->draw(m_gameWindow);
}

void GameManager::restartObjectLoc()
{
	for (int i = 0; i < m_objectMoving.size(); i++)
		m_objectMoving[i]->restartLoc();
}

void GameManager::drawManager()
{
	m_gameWindow.clear();
	m_boardTiles.draw(m_gameWindow);
	m_gameInfo.updateStatusText();
	m_gameInfo.drawInfo(m_gameWindow);
	drawObjects();
	m_gameWindow.display();
}

void GameManager::drawBackground()
{
	Background image(GameConsts::NAME_FILE_IMAGE_BACKGROUND, m_sizeWindow);
	image.background(m_gameWindow);
}

void GameManager::drawFinishGame()
{
	Background imageFinish(GameConsts::NAME_FILE_IMAGE_FINISH, m_sizeWindow);
	imageFinish.background(m_gameWindow);
}

void GameManager::displayError(GameException& error)
{
	ErrorWindow displayerror(error);
	displayerror.display();
}

void GameManager::drawStartBackground()
{
	if (m_gameInfo.getNumLevel() == 1)
		drawFinishGame();
	else
		drawBackground();
}


void GameManager::setAllInfo(int playerLives, float timeLevel)
{
	m_gameInfo.setPlayerLives(playerLives);
	m_gameInfo.setNumEnemys(m_numEnemies);
	m_gameInfo.setCountDown(timeLevel);
	m_gameInfo.setScore(m_gameInfo.getScore());
	m_gameInfo.setSizeWindow(m_sizeWindow);
	m_gameInfo.setnumLevel(m_gameInfo.getNumLevel()+1);
	m_gameInfo.setCapturedPercent(0);
	m_gameInfo.setTileCoun(0); 
	m_gameInfo.setCapturedArea(m_neededArea);
}


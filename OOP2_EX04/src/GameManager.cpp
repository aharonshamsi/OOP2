#include "GameManager.h"
#include "DisplayError.h"

GameManager::GameManager()
{}

void GameManager::run() {

	try
	{
		std::ifstream filePlaylist(GameConsts::NAME_FLAYLIST_LEVEL);
		if (!filePlaylist.is_open())
			throw GameException("Error: Failed to open playlist file!\n");


		std::string nameLevel;

		while (std::getline(filePlaylist, nameLevel)) { // קורא שם קובץ שלב מהפלליליס
			
			std::string infoLevel;
			readLevel(nameLevel, infoLevel);  // קורא פתוח קובץ השלב את הנתונים
			initGameInfo(infoLevel);  // עם הנתונים שקרא info מאתחל את האויביקט  
			initGameWindow();


			// לולאת המשחק=================
			while (m_gameWindow.isOpen()) {
				sf::Event event;

				while (m_gameWindow.pollEvent(event)) {
					if (event.type == sf::Event::Closed) 
						m_gameWindow.close();

					// פה נטפל בתזוזה
				}

				m_gameWindow.clear();
				// פה יהיה לוגיקה של תזוזות


				// עדכון הנתונים טקסט התחתית
				m_gameInfo.updateStatusText(); 
				m_gameInfo.drawInfo(m_gameWindow);
				m_gameWindow.display();
			}
		}
		//m_gameInfo.setnumLevel()
		//m_gameInfo.resetInfo(); //נאפס את הנתונים

	}

	catch (GameException& error)
	{
		std::cout << error.what();
		displayError(error);
	}

}

//====================================================================
void GameManager::readLevel(std::string& nameLevel, std::string& infoLevel)
{
	std::ifstream fileLevel(nameLevel);
	if (!fileLevel.is_open())
		throw GameException("Error: Failed to open level file: " + nameLevel);
	std::getline(fileLevel, infoLevel);
}

//====================================================================
void GameManager::initGameInfo(std::string& infoLevel)
{
	int goalPercent; 
	int numEnemies; 
	int playerLives;
	float timeLevel;

	std::istringstream lineStream(infoLevel);

	if (!(lineStream >> goalPercent >> numEnemies >>
		m_sizeWindow.x >> m_sizeWindow.y >> playerLives >> timeLevel)) {
		throw GameException("Error: Invalid data format in level file! \n");
	}

	m_gameInfo.setGoalPercent(goalPercent);
	m_gameInfo.setNumEnemies(numEnemies);
	m_gameInfo.setPlayerLives(playerLives);
	m_gameInfo.setCountDown(timeLevel);
	m_gameInfo.setScore(m_gameInfo.getScore());
	m_gameInfo.setSizeWindow(m_sizeWindow);
	m_gameInfo.setnumLevel(m_gameInfo.getNumLevel()+1); // נגדיל את מספר השלב


	m_gameInfo.initStatusBar(m_gameWindow);

	std:: cout <<"The level is: "<< m_gameInfo.getNumLevel() << std::endl; // הדפסת השלב
	std::cout << m_gameInfo.getGoalPercent() << " ";
}


//====================================================================
void GameManager::initGameWindow()
{
	m_gameWindow.create(sf::VideoMode(static_cast<unsigned int>(m_sizeWindow.x),
		static_cast<unsigned int>(m_sizeWindow.y)), GameConsts::NAME_GAME);
}


//====================================================================
void GameManager::displayError(GameException& error)
{
	DisplayError displayerror(error, m_gameWindow);
	displayerror.display();
}


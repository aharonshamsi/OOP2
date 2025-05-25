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

		while (std::getline(filePlaylist, nameLevel)) { //צריך לטפל שאם נגמר חיים של שלב המשחק צריך להסתיים לגמרי ולא לעבור לשלב הבא 
			
			// ניתן פה להדפיס מעבר שלב עם השהייה

			std::string infoLevel;
			readLevel(nameLevel, infoLevel);  // קורא פתוח קובץ השלב את הנתונים
			initGameInfo(infoLevel);  // עם הנתונים שקרא info מאתחל את האויביקט  
			initGameWindow(); // מעדכן גודל חלון
			m_boardTiles.initTileBoard(m_sizeWindow);
			createObject(); // יוצרת את ההאובייקטים בווקטור בהתאם לנתוני הקובץ

			sf::Clock clock; // יצירת שעון
			clock.restart();

			// לולאת המשחק=================
			while (m_gameWindow.isOpen() && m_gameInfo.getPlayerLives() > 0) {

				auto time = clock.restart().asSeconds(); // שומר זמן מקריאה לקיאה ומאפס

				sf::Event event;
				while (m_gameWindow.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						m_gameWindow.close();
				}

				// תזוזות
				for (int i = 0; i < m_objectMoving.size(); i++) {
					m_objectMoving[i]->move(time, m_boardTiles, m_gameInfo);

					for (int j = 0; j < m_objectMoving.size(); j++) {
						if (i != j)
							m_objectMoving[i]->handleCollision(*m_objectMoving[j], m_gameInfo);
					}
				}

				// אם היה כבישה של שטח נעדכן לוח ונתנוים
				if (m_gameInfo.getNeedAreaCheck()) { // צריך לעדכן שיכנס רק מתי שהחקן על מצב שובל דחוף וחובה
					m_boardTiles.markCapturedArea();
					m_gameInfo.setNeedAreaCheck(false);
				}

				// בדיקת פסול אחרי כל הלוגיקה
				if (m_gameInfo.getIsViolation()) {
					restartObjectLoc(); // איפוס מיקום שחקן
					m_boardTiles.restartTrail();    // איפוס שובל הלוח
					m_gameInfo.restartViolation();; // איפוס הדגל
					continue;                        
				}


				m_gameWindow.clear();
				m_boardTiles.draw(m_gameWindow);
				m_gameInfo.updateStatusText();
				m_gameInfo.drawInfo(m_gameWindow);
				drawObjects();
				m_gameWindow.display();


				if (m_gameInfo.getCapturedPercent() > m_neededArea)
					break;
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
		throw GameException("Error: \n   Failed to open level file: " + nameLevel);
	std::getline(fileLevel, infoLevel);
}

//====================================================================
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

	std:: cout <<"The level is: "<< m_sizeWindow.x << " " << m_sizeWindow.y <<" "; // הדפסת השלב
	std::cout << m_gameInfo.getGoalPercent() << " ";
}


//====================================================================
void GameManager::initGameWindow()
{
	m_gameWindow.create(sf::VideoMode(static_cast<unsigned int>(m_sizeWindow.x),
		static_cast<unsigned int>(m_sizeWindow.y)), GameConsts::NAME_GAME);
	m_gameWindow.clear();
	m_gameWindow.setFramerateLimit(60); //  הגבלת FPS

}


void GameManager::createObject()
{
	m_objectMoving.clear();
	sf::Vector2f locPlayer = m_boardTiles.getTileLocByIndex(29/*m_boardTiles.getCols() / 2*/, 0);

	m_objectMoving.push_back(std::make_unique<Player>(locPlayer, m_boardTiles.getSizeTile()));
	// מגריל מיקם רנדומאלי לאוייבים
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

void GameManager::setAllInfo(int playerLives, float timeLevel)
{
	m_gameInfo.setPlayerLives(playerLives);
	m_gameInfo.setNumEnemys(m_numEnemies);
	m_gameInfo.setCountDown(timeLevel);
	m_gameInfo.setScore(m_gameInfo.getScore());
	m_gameInfo.setSizeWindow(m_sizeWindow);
	m_gameInfo.setnumLevel(m_gameInfo.getNumLevel()+1); // נגדיל את מספר השלב
	m_gameInfo.setCapturedPercent(0);
	m_gameInfo.setTileCoun(0); // נאפס את מספר האריחים שנכבשו בתור שעבר
	m_gameInfo.initStatusBar(m_sizeWindow);

}


//====================================================================
void GameManager::displayError(GameException& error)
{
	ErrorWindow displayerror(error);
	displayerror.display();
}


#include "GameControler.h"
#include "GameData.h"

GameControler::GameControler()
	: m_window(sf::VideoMode(GameData::SIZE_GAME_WINDOW.x, GameData::SIZE_GAME_WINDOW.y), "Geometry Dash"), 
	m_menuManager() 
{}


//void GameControler::run()
//{
//	while (m_window.isOpen()) {
//
//		sf::Event event;
//		while (m_window.pollEvent(event)) {
//			if (event.type == sf::Event::Closed) {
//				m_window.close();
//				return;
//			}
//			m_menuManager.runMenu(event);
//		}
//
//	}
//}

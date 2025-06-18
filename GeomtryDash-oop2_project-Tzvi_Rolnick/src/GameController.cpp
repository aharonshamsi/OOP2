#include "GameController.h"
#include <iostream>
#include <fstream>
#include "GameObject/MovingObject/Player.h"
#include "GameObject/MovingObject/Enemy.h"
#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/Factory.h"
#include "GameMenu/MenuAction.h"

GameController::GameController()
	: m_window(sf::VideoMode(800, 900), "Geometry Dash"), m_menuManager(), m_background{"bg.png"}
{

	readFromFile();

}
//-------------------------------------
void GameController::run()
{
	
	while (!m_need2exit) {

			m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 900.f)));
			m_menuManager.runMenu(m_menuInfo, m_window);
			m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 900.f)));

			handleMenu();
			updateAfterLevel();	
	}

}
//-------------------------------------
void GameController::mainLoop()
{

	m_clock.restart();// not to get a lot of time itch time that the function called
	while (m_window.isOpen()) {

		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				/*m_window.close();
				m_need2exit = true;*/
				return;
			}
		}
		handleEvent();
		handleCollisionController();
		draw();

	}
}
//-------------------------------------
void GameController::handleEvent()
{
	deleteObjFromVec();
	// maybe move is separate function and update direction is a separate function
	for (const auto& MovObj : m_movingObjVec)
		MovObj->updateDirection();

	auto deltaTime = m_clock.restart().asSeconds();
	for (const auto& MovObj : m_movingObjVec)
		MovObj->move(deltaTime);

	auto view = m_window.getView();
	view.move(sf::Vector2f{ deltaTime * 150, 0.f });
	m_window.setView(view);

}
//-------------------------------------
void GameController::deleteObjFromVec()
{
	std::erase_if(m_movingObjVec, [](const auto& obj) { return obj->isDead(); });
	//std::erase_if(m_staticObjVec, [](const auto& obj) { return obj->isDead(); });// maybe in i will be able to shot static object and to kill them
}
//-------------------------------------
void GameController::draw()
{
	m_window.clear();
	m_background.draw(m_window);
	for (const auto& staticObj : m_staticObjVec)
		staticObj->draw(m_window);
	for (const auto& movingObj : m_movingObjVec)
		movingObj->draw(m_window);

	m_information.draw(m_window);
	m_window.display();
}
//-------------------------------------
void GameController::handleCollisionController()
{


}
//-------------------------------------
void GameController::handleMenu()
{
	ImagesObject images;

	MenuAction action = m_menuManager.runMenu(m_menuInfo, m_window);
	if (action == MenuAction::StartLevel )
	{
		analyzeLevel();
		mainLoop();
	}
	else if (action == MenuAction::ExitGame)
	{
		m_need2exit = true;
		//m_window.close();
	}
}
//-------------------------------------
void GameController::analyzeLevel()
{
	ImagesObject images;



	std::fstream file("level" + std::to_string(m_information.getNumLevel()) + ".txt");
	if (!file.is_open())
	{
		std::cerr << "Error: Failed to open file: Level" << m_information.getNumLevel() << ".txt" << std::endl;
		return;
	}

	// Add logic to read from the file here...
	char c;
	int row = 0, col = 0;
	while (file >> std::noskipws >> c) {

		sf::Vector2f loc{ static_cast<float>(col) * 50.f, static_cast<float>(row) * 50.f
		};
		auto obj = Factory::create(c, loc, images, m_menuInfo.getTypePlayer());

		if (auto mo = dynamic_cast<MovingObject*>(obj.get()))
			m_movingObjVec.push_back(std::unique_ptr<MovingObject>(static_cast<MovingObject*>(obj.release())));
		else if (auto so = dynamic_cast<StaticObject*>(obj.get()))
			m_staticObjVec.push_back(std::unique_ptr<StaticObject>(static_cast<StaticObject*>(obj.release())));
		col++;
		if (c == '\n')
		{
			row++;
			col = 0;
		}
	}
	  
	file.close();


	
}
//-------------------------------------
void GameController::updateInformation()
{
}
//-------------------------------------
void GameController::updateAfterLevel()
{
	m_movingObjVec.clear();
	m_staticObjVec.clear();
}

void GameController::readFromFile()
{

}

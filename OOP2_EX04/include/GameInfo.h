#pragma once
#include <SFML/Graphics.hpp>
#include "GameConsts.h"

class GameInfo {

public:

    GameInfo();

    // Setters
    void setGoalPercent(int percent) { m_goalPercent = percent; }
    void setNumEnemies(int numEnemies) { m_numEnemies = numEnemies; }
    void setPlayerLives(int playerLives) { m_playerLives = playerLives; }
    void setnumLevel(int numLevel) { m_nunLevel = numLevel; }
    void setScore(int score) { m_score = score; };
    void setCountDown(const float countDown) { m_countDown = countDown; };
    void setSizeWindow(sf::Vector2f size) { m_sizeWindow = size; };

    void initStatusBar(sf::RenderWindow& window); // יצירת טקסט גרפי של הנתונים בחלון למטה
    void updateStatusText(); // עדכון קריאת הטקסט בכל פריים 
    void drawInfo(sf::RenderWindow& window);


    // Getters
    int getGoalPercent() const { return m_goalPercent; }
    int getNumEnemies() const { return m_numEnemies; }
    int getPlayerLives() const { return m_playerLives; }
    int getNumLevel() const { return m_nunLevel; }
    int getScore() const { return m_score; };

    void resetInfo();

private:
	int m_goalPercent; // אחוז לנצחון
	int m_numEnemies; //  מספר אוייבים
	int m_playerLives; // מספר חיים
    int m_nunLevel;
    int m_score;
    float m_countDown;

    sf::RectangleShape m_shape;
    sf::Vector2f m_sizeWindow;
    sf::Text m_text;
    sf::Font m_font;

};


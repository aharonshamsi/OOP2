#pragma once
#include <SFML/Graphics.hpp>
#include "GameConsts.h"

class GameInfo {

public:

    GameInfo();

    // Setters
    void setCapturedArea(int captureArea) { m_capturedArea = captureArea; }  // אחוז השטח שכבש
    void setPlayerLives(int playerLives) { m_playerLives = playerLives; }
    void setnumLevel(int numLevel) { m_nunLevel = numLevel; }
    void setScore(int score) { m_score = score; };
    void setCountDown(const float countDown) { m_countDown = countDown; };
    void setSizeWindow(sf::Vector2f size) { m_sizeWindow = size; };


    // Getters
    int getGoalPercent() const { return m_capturedArea; }
    int getPlayerLives() const { return m_playerLives; }
    int getNumLevel() const { return m_nunLevel; }
    int getScore() const { return m_score; };


    void initStatusBar(sf::Vector2f sizeWindow); // יצירת טקסט גרפי של הנתונים בחלון למטה
    void updateStatusText(); // עדכון קריאת הטקסט בכל פריים 
    void drawInfo(sf::RenderWindow& window);
    void updateRemainingTime(int& minutes, int& seconds);
    void resetInfo();



private:
	int m_capturedArea; // אחוז לנצחון
	int m_playerLives; // מספר חיים
    int m_nunLevel;
    int m_score;

    sf::Clock m_timer;
    float m_countDown;


    sf::RectangleShape m_shape;
    sf::Vector2f m_sizeWindow;
    sf::Text m_text;
    sf::Font m_font;

};


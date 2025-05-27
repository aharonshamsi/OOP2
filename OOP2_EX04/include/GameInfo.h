#pragma once
#include <SFML/Graphics.hpp>
#include "GameConsts.h"

class GameInfo {
public:
    GameInfo();

    // Setters
    void setCapturedArea(int captureArea) { m_capturedArea = captureArea; }
    void setPlayerLives(int playerLives) { m_playerLives = playerLives; }
    void setnumLevel(int numLevel) { m_nunLevel = numLevel; }
    void setScore(int score) { m_score = score; }
    void setCountDown(const float countDown) { m_countDown = countDown; }
    void setSizeWindow(sf::Vector2f size) { m_sizeWindow = size; }
    void setIsViolation(bool violation) { m_isViolation = violation; }
    void setNeedAreaCheck(bool needAreaCheck) { m_needAreaCheck = needAreaCheck; }
    void setNumEnemys(int num) { m_numEnemys = num; }
    void setCapturedPercent(int num);
    void setTileCoun(int num);

    // Getters
    int  getGoalPercent()    const { return m_capturedArea; }
    int  getPlayerLives()    const { return m_playerLives; }
    int  getNumLevel()       const { return m_nunLevel; }
    int  getScore()          const { return m_score; }
    bool getIsViolation()    const { return m_isViolation; }
    bool getNeedAreaCheck()  const { return m_needAreaCheck; }
    int  getCapturedPercent() const;
    sf::Vector2f getSizeWindow() const { return m_sizeWindow; }

    // Functional
    void restartViolation();
    void resetInfo();
    void updateRemainingTime(int& minutes, int& seconds);
    void updateCapturedArea(int filledTiles, int totalTiles);
    void addScoreForCaptured(int filledTiles);
    void initStatusBar(sf::Vector2f& sizeWindow);
    void updateStatusText();
    void drawInfo(sf::RenderWindow& window);


private:
    int m_capturedArea; 
    int m_playerLives;
    int m_nunLevel;
    int m_score;
    int m_tileCoun;
    int m_numEnemys;
    int m_capturedPercent;
    bool m_isViolation;
    bool m_needAreaCheck;

    // Timer
    sf::Clock m_timer;
    float m_countDown;

    sf::RectangleShape m_shape;
    sf::Vector2f m_sizeWindow;
    sf::Text m_text;
    sf::Font m_font;
};

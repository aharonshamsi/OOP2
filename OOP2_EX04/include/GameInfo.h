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
    bool getIsViolation() const { return m_isViolation; };
    void setIsViolation(bool violation) { m_isViolation = violation; };

    bool getNeedAreaCheck() const { return m_needAreaCheck; };
    void setNeedAreaCheck(bool needAreaCheck) { m_needAreaCheck = needAreaCheck; };

    void setNumEnemys(int num) { m_numEnemys = num; };

    void restartViolation(); // פונצקיה שמעדכנת את כל הנתונים של האינפורצמיה בסרגל נתונים

    void initStatusBar(sf::Vector2f& sizeWindow); // יצירת טקסט גרפי של הנתונים בחלון למטה
    void updateStatusText(); // עדכון קריאת הטקסט בכל פריים 
    void drawInfo(sf::RenderWindow& window);
    void updateRemainingTime(int& minutes, int& seconds);

    void updateCapturedArea(int filledTiles, int totalTiles); // עדכחן שטח נכבש
    int getCapturedPercent() const;
    void setCapturedPercent(int num);
    void setTileCoun(int num);

    void addScoreForCaptured(int filledTiles); // מעדכן העלעת נקודות


private:
	int m_capturedArea; // אחוז לנצחון
	int m_playerLives; // מספר חיים
    int m_nunLevel;
    int m_score;
    int m_tileCoun; // מספר הארחים שנכבשו בכל תור לצורך ניקוד
    int m_numEnemys; // מספר שומרים כנראה אין בו שימוש אז למחוק בהמשך אם לא נצרטך כולל הפונקציות גט וסט שלו
    int m_capturedPercent; // אחוז שהשחקן תפס
    bool m_isViolation; // ממבר שהיה פסול
    bool m_needAreaCheck; // 


    sf::Clock m_timer;
    float m_countDown;


    sf::RectangleShape m_shape;
    sf::Vector2f m_sizeWindow;
    sf::Text m_text;
    sf::Font m_font;

};


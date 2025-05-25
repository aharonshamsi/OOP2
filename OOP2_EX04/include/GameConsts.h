#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace GameConsts {
    inline const std::string NAME_GAME = "Game Xonix"; // שם חלון המשחק
    inline const std::string NAME_ERROR = "Error Window"; // שם חלון שגיאה
    inline const std::string NAME_FLAYLIST_LEVEL = "playlistLevels.txt"; // שם קובץ הפליליס של שלבים

    inline const float HIGHT_SHAPE_INFO = 100.f; //  גובה לוח איפורמציה 

    extern const sf::Color COLOR_SHAPE_INFO; // צבע המלבן
    extern const sf::Color COLOR_TEXT_INFO;  // צבע הטקסט

    extern const sf::Color COLOR_FRAME;     // צבע גבולות חלון המשחק
    extern const sf::Color COLOR_EMPTY;     // צבע שטח ריק
    extern const sf::Color COLOR_TRAIL;     // צבע שובל של השחקן
    extern const sf::Color COLOR_FILLED;    // צבע שטח שנכבש


    extern const unsigned int SIZE_CHARACTER; // גודל פונט
    extern const unsigned int POINTS_PER_TILE; // פקטור נקודות לאריח
    extern const unsigned int OVER_CAPTURE_BONUS; // פקטור לכובש יותר 10 אחוז מהנדרש

    extern sf::Vector2f sizeTile; // גודל אריח
}

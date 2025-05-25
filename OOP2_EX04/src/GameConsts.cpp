#include "GameConsts.h"

namespace GameConsts {
    const sf::Color COLOR_SHAPE_INFO = sf::Color(0, 70, 80);
    const sf::Color COLOR_TEXT_INFO = sf::Color::Black;

    const sf::Color COLOR_FRAME = sf::Color(0, 120, 120); // מסגרת
    const sf::Color COLOR_EMPTY  = sf::Color::Black;
    const sf::Color COLOR_TRAIL = sf::Color(128, 0, 32); // שטח כבוש
    const sf::Color COLOR_FILLED = sf::Color(0, 120, 120); // שובל מסלול
     

    const unsigned int SIZE_CHARACTER = 25;

    const unsigned int POINTS_PER_TILE = 10; // נקודות עבור כל אריח
    const unsigned int OVER_CAPTURE_BONUS = 1000;
    

    sf::Vector2f sizeTile = { 20.f, 20.f };
}

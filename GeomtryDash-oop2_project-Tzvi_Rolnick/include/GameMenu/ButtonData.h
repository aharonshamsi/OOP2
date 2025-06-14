#pragma once
#include <SFML/Graphics.hpp>

namespace ButtonData {

    const sf::Vector2f SIZE_BUTTON = { 100.f, 100.f }; // גודל כפתור
    const sf::Vector2f SIZE_ICON_BUTTON = { 70.f, 70.f }; //  גודל כפתור יוטיוב וגיט חזור ביצוע

    const sf::Vector2f LOC_START = { 80.f, 700.f }; // מיקום כפתור התחלה
    const sf::Vector2f LOC_EXIT = { 260.f, 700.f }; // מיקום כפתור יציאה
    const sf::Vector2f LOC_HELP = { 440.f, 700.f }; // מיקום כפתור עזרה
    const sf::Vector2f LOC_STORE = { 620.f, 700.f }; // מיקום כפתור חנות

    const sf::Vector2f LOC_WATCH = { 0.f, 830.f }; // מיקום כפתור צפיה במשחק
    const sf::Vector2f LOC_GIT_HUB = { 730.f, 830.f }; // מיקום כפתור gitHub

    const sf::Vector2f LOC_DONE = { 320.f, 770.f }; // מיקום כפתור gitHub
    const sf::Vector2f LOC_CANCEL = { 410.f, 770.f }; // מיקום כפתור gitHub


    // קבועים של דמויות חנות
    const sf::Vector2f SIZE_BUY_PLAYER = { 140.f, 140.f }; // גודל דמות שחקן בחנות

    const sf::Vector2f LOC_PAYER_ALPHA= { 160.f, 295.f }; // מיקום דמות שחקן 1 בחנות
    const sf::Vector2f LOC_PAYER_BETA = { 330.f, 295.f }; // מיקום דמות שחקן 2 בחנות
    const sf::Vector2f LOC_PAYER_GAMMA = { 500.f, 295.f }; // מיקום דמות שחקן 3 בחנות
    const sf::Vector2f LOC_PAYER_DELTA = { 160.f, 490.f }; // מיקום דמות שחקן 4 בחנות
    const sf::Vector2f LOC_PAYER_EPSILON = { 330.f, 490.f }; // מיקום דמות שחקן 5 בחנות
    const sf::Vector2f LOC_PAYER_ZETA = { 500.f, 490.f }; // מיקום דמות שחקן 6 בחנות

}

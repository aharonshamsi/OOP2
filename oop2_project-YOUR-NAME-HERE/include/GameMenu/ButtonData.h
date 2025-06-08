#pragma once
#include <SFML/Graphics.hpp>

namespace ButtonData {

    const sf::Vector2f SIZE_BUTTON = { 100.f, 100.f }; // גודל כפתור
    const sf::Vector2f SIZE_ICON_BUTTON = { 70.f, 70.f }; // גודל כפתור יוטיוב וגיט

    const sf::Vector2f LOC_START = { 80.f, 700.f }; // מיקום כפתור התחלה
    const sf::Vector2f LOC_EXIT = { 260.f, 700.f }; // מיקום כפתור יציאה
    const sf::Vector2f LOC_HELP = { 440.f, 700.f }; // מיקום כפתור עזרה
    const sf::Vector2f LOC_STORE = { 620.f, 700.f }; // מיקום כפתור חנות

    const sf::Vector2f LOC_WATCH = { 0.f, 830.f }; // מיקום כפתור צפיה במשחק
    const sf::Vector2f LOC_GIT_HUB = { 730.f, 830.f }; // מיקום כפתור צפיה במשחק

}

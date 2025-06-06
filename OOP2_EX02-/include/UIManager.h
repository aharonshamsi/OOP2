#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>
#include "DialogueManager.h"

// מחלקה של ניהול ממשק משתמש
class UIManager {
private:
    sf::RenderWindow& window; // חלון לפתיחה
    DialogueManager& formManager; // מנהל דיאלוג כל הטפסים

    // ✅ Fix: Declare buttons and texts
    // כפתורים טקסטים ופונט של חלון הפתיחה
    sf::Font font;
    sf::RectangleShape buttonFlight, buttonHotel, buttonCar, buttonEvent, buttonTrain;
    sf::Text textFlight, textHotel, textCar, textEvent, textTrain;

    // ✅ Fix: Declare setupButton
    void setupButton(sf::RectangleShape& button, sf::Text& text, const std::string& label, float y);

public:
    UIManager(sf::RenderWindow& win, DialogueManager& dManager);
    void handleEvent(const sf::Event& event);
    void render();
};

#endif // UIMANAGER_H

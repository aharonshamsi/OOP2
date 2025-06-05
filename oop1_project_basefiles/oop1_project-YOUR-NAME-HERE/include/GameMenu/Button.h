#pragma once
#include "GameMenu/TypeButton.h"
#include "GameMenu/ImagesButtons.h"

class Button {

public:
    Button(const TypeButton& type, const sf::Vector2f& location, const sf::Vector2f& wantedSize);

    void draw(sf::RenderWindow& window);

    //bool isPressed(const sf::Vector2f locPressed); // פונציה שמחזירה טרו אם מקום הלחיצה בתוך מקום בכפתור

private:

    TypeButton m_type;
    sf::Sprite m_sprite;
    sf::Vector2f m_location;
    //bool m_pressed;

    void updateSpritesForAll(const sf::Vector2f& wantedSize);
};
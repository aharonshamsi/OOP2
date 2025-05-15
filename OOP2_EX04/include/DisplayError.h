#pragma once
#include "GameException.h"
#include <SFML/Graphics.hpp>


class DisplayError {

public:
    DisplayError(const GameException& exception, sf::RenderWindow& window)
        : m_exception(exception), m_window(window) {}

    void display() {
        sf::Font font;
        if (!font.loadFromFile("Athelas.ttc")) {
            return; // לממש זריקה אם לא מצאתי את הפונט
        }

        sf::Text text;
        text.setFont(font);
        text.setString(m_exception.what());
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setPosition(50.f, 50.f);

        m_window.clear();
        m_window.draw(text);
        m_window.display();

        sf::sleep(sf::seconds(10)); // הצגה של זמן ההודעה
    }

private:
    const GameException& m_exception;
    sf::RenderWindow& m_window;
};

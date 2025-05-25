#include "ErrorWindow.h"

ErrorWindow::ErrorWindow(const GameException exception)
    : m_erroeWindow(sf::VideoMode(1700, 800), GameConsts::NAME_ERROR),
    m_exception(exception)
{}

void ErrorWindow::display()
{
    sf::Font font;
    if (!font.loadFromFile("Athelas.ttc")) {
        return; // לממש זריקה אם לא מצאתי את הפונט
    }
    while (m_erroeWindow.isOpen()) {  // נבדוק שלא סיים את יעד הכבישה m_neededArea וכן שלא נגמר זמן וחיים 
        sf::Event event;

        while (m_erroeWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_erroeWindow.close();

            sf::Text text;
            text.setFont(font);
            text.setString(m_exception.what());
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Red);
            text.setPosition(50.f, 50.f);

            m_erroeWindow.clear();
            m_erroeWindow.draw(text);
            m_erroeWindow.display();
        }

    }
}

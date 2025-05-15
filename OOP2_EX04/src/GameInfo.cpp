#include "GameInfo.h"
#include "GameInfo.h"
#include "GameInfo.h"
#include "GameInfo.h"

GameInfo::GameInfo()
:m_goalPercent(0),
m_numEnemies(0),
m_playerLives(0),
m_nunLevel(0),
m_score(0),
m_countDown(0),
m_sizeWindow(0, 0)
{}

// עדכון מיקום הטקסט והצורה בתחתית החלון
void GameInfo::initStatusBar(sf::RenderWindow& window)
{
    m_font.loadFromFile("Athelas.ttc");
    m_text.setFont(m_font);
    m_text.setCharacterSize(GameConsts::SIZE_CHARACTER);
    m_text.setFillColor(GameConsts::COLOR_TEXT_INFO);

    // קביעת הצורה של המלבן
    m_shape.setSize(sf::Vector2f(m_sizeWindow.x, m_sizeWindow.y / 10));
    m_shape.setPosition(0.f, m_sizeWindow.y - m_shape.getSize().y);
    m_shape.setFillColor(sf::Color(GameConsts::COLOR_SHAPE_INFO));
}

// עדכון קריאת הטקסט בכל פריים 
void GameInfo::updateStatusText()
{
    std::string info = "Level: " + std::to_string(m_nunLevel) +
        "    Goal: " + std::to_string(m_goalPercent) + "%" +
        "    Enemies: " + std::to_string(m_numEnemies) +
        "    Lives: " + std::to_string(m_playerLives) +
        "    Score: " + std::to_string(m_score);

    m_text.setString(info);

    // חישוב מיקום טקסט חדש במרכז המלבן (אם האורך של הטקסט משתנה)
    sf::FloatRect textBounds = m_text.getLocalBounds();
    m_text.setPosition(
        (m_sizeWindow.x - textBounds.width) / 2.f,
        m_sizeWindow.y - m_shape.getSize().y + (m_shape.getSize().y - textBounds.height) / 2.f - textBounds.top
    );
}


void GameInfo::drawInfo(sf::RenderWindow& window)
{
    window.draw(m_shape);
    window.draw(m_text);
}


void GameInfo::resetInfo()
{
    m_goalPercent = 0;
    m_numEnemies = 0;
    m_playerLives = 0;
}

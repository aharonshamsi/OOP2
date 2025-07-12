#include "GameInfo.h"
#include <iostream>

GameInfo::GameInfo()
:m_capturedArea(0),
m_playerLives(0),
m_nunLevel(0),
m_score(0),
m_tileCoun(0),
m_capturedPercent(0),
m_numEnemys(0),
m_countDown(0),
m_sizeWindow(0, 0),
m_isViolation(false),
m_needAreaCheck(false)
{}

void GameInfo::initStatusBar(sf::Vector2f& sizeWindow)
{
    m_font.loadFromFile("Athelas.ttc");
    m_text.setFont(m_font);
    m_text.setCharacterSize(GameConsts::SIZE_CHARACTER);
    m_text.setFillColor(GameConsts::COLOR_TEXT_INFO);

    int hightToolbar = static_cast<int> (sizeWindow.y / 100);
    m_shape.setSize(sf::Vector2f(sizeWindow.x, sizeWindow.y / hightToolbar));
    m_shape.setPosition(0.f, sizeWindow.y - m_shape.getSize().y);
    m_shape.setFillColor(sf::Color(GameConsts::COLOR_SHAPE_INFO));
}

void GameInfo::updateStatusText()
{
    int minutes, seconds;
    updateRemainingTime(minutes, seconds);

    std::string info = "Level: " + std::to_string(m_nunLevel) +
        "    Won: " + std::to_string(getCapturedPercent()) + "%" +
        "    Lives: " + std::to_string(m_playerLives) +
        "    Score: " + std::to_string(m_score) +
        "    Time: " + (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + std::to_string(seconds);

    m_text.setString(info);

    sf::FloatRect textBounds = m_text.getLocalBounds();
    m_text.setPosition(
        (m_sizeWindow.x - textBounds.width) / 2.f,
        m_sizeWindow.y - m_shape.getSize().y + 
        (m_shape.getSize().y - textBounds.height) / 2.f - textBounds.top
    );

}


void GameInfo::drawInfo(sf::RenderWindow& window)
{
    window.draw(m_shape);
    window.draw(m_text);
}


void GameInfo::resetInfo()
{
    m_capturedArea = 0;
    m_playerLives = 0;
    m_countDown = 0;
    m_numEnemys = 0;
    m_capturedPercent = 0;
}

int GameInfo::getCapturedPercent() const
{
    return static_cast<int>(m_capturedPercent);
}

void GameInfo::setCapturedPercent(int num)
{
    m_capturedPercent = num;
}

void GameInfo::setTileCoun(int num)
{
    m_tileCoun = num;
}

void GameInfo::updateRemainingTime(int& minutes, int& seconds)
{
    float elapsedTime = m_timer.restart().asSeconds();
    m_countDown -= elapsedTime;
    minutes = static_cast<int> (m_countDown) / 60;
    seconds = static_cast<int> (m_countDown) % 60;
}



void GameInfo::updateCapturedArea(int filledTiles, int totalTiles)
{
    if (totalTiles == 0)
        m_capturedPercent = 0;
    else
        m_capturedPercent = static_cast<int> (100.f * filledTiles) / totalTiles;

    if (m_capturedPercent >= m_capturedArea + 10)  // Compression factor 10+
        m_score = m_score + GameConsts::OVER_CAPTURE_BONUS;
}


void GameInfo::addScoreForCaptured(int filledTiles)
{
    int newCapturedTiles = filledTiles - m_tileCoun;

    if (newCapturedTiles > 0) {
        m_score += newCapturedTiles * GameConsts::POINTS_PER_TILE;
        m_tileCoun = filledTiles;
    }
}



void GameInfo::restartViolation()
{
    m_isViolation = false;
    m_playerLives = m_playerLives - 1;
}

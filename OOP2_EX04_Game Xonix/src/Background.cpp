#include "Background.h"

Background::Background(const std::string& nameFile, const sf::Vector2f& size)
{

    if (!m_texture.loadFromFile(nameFile))
        throw GameException("Error: \n    Failed to load enemy image(file not found).");

    m_sprite.setTexture(m_texture);

    m_sprite.setScale(
        size.x / m_texture.getSize().x,
        size.y / m_texture.getSize().y
    );
}

void Background::background(sf::RenderWindow& window)
{
    window.clear();
    window.draw(m_sprite);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear(); 
}


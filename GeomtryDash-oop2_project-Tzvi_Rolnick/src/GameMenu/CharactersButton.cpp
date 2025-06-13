#include "GameMenu/CharactersButton.h"

CharactersButton::CharactersButton(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(location)
{
}

void CharactersButton::scaleCharacters(const sf::Vector2f& wantedSize)
{
    sf::FloatRect bounds = m_sprite.getLocalBounds();

    float scaleX = wantedSize.x / bounds.width;
    float scaleY = wantedSize.y / bounds.height;

    m_sprite.setScale(scaleX, scaleY);
}

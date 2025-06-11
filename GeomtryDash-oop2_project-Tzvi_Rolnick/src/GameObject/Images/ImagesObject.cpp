#include <stdexcept>
#include "GameObject/Images/ImagesObject.h"

std::vector<sf::Texture> ImagesObject::m_imagesObject;

ImagesObject::ImagesObject()
{
    loadAllImages();
}

void ImagesObject::loadAllImages()
{
    m_imagesObject.resize(static_cast<int>(TypeObject::count));

    loadImageSpriteSheet();
}

void ImagesObject::loadImageSpriteSheet()
{
    if(!m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)].loadFromFile("GeometryDashSpriteSheet.png"))
        std::cout << "Error: \n    Failed to load GeometryDashSpriteSheet image (file not found).";

}



sf::Sprite ImagesObject::getSpriteObject(const TypeObject& type) const
{
    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)]);

    switch (type)
    {

    case TypeObject::Enemy:
        sprite.setTextureRect(sf::IntRect(100, 584, 50, 50));
        break;

    case TypeObject::Obstacle:
        sprite.setTextureRect(sf::IntRect(440, 430, 50, 50));
        break;

    case TypeObject::PlayerOne:
        sprite.setTextureRect(sf::IntRect(639, 710, 50, 50));
        break;

    default:
        return sf::Sprite(); 
    }

    return sprite; 
}

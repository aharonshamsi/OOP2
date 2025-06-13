#include <stdexcept>
#include "GameObject/Images/ImagesObject.h"

std::vector<sf::Texture> ImagesObject::m_imagesObject;



void ImagesObject::loadAllImagesObject()
{
    m_imagesObject.resize(static_cast<int>(TypeObject::count));
    loadImageSpriteSheet();
    loadPlayerCharacters();
}


void ImagesObject::loadImageSpriteSheet()
{
    if(!m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)].loadFromFile("GeometryDashSpriteSheet.png"))
        std::cout << "Error: \n    Failed to load GeometryDashSpriteSheet image (file not found).";

}

void ImagesObject::loadPlayerCharacters()
{
    if (!m_imagesObject[static_cast<int>(TypeObject::PlayerCharacters)].loadFromFile("PlayerCharacters.png"))
        std::cout << "Error: \n    Failed to load Player Characters image (file not found).";
}



sf::Sprite ImagesObject::getSpriteObject(const TypeObject& type)
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


    case TypeObject::player:
        sprite.setTextureRect(sf::IntRect(639, 710, 50, 50));
        break;

    case TypeObject::PlayerOne:
        sprite.setTextureRect(sf::IntRect(490, 660, 32, 32));
        break;


    default:
        return sf::Sprite(); 
    }

    return sprite; 
}


sf::Sprite ImagesObject::getSpritePlayer(const TypeObject& type)
{
    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::PlayerCharacters)]);

    switch (type)
    {

    case TypeObject::player:
        sprite.setTextureRect(sf::IntRect(367, 785, 270, 263));
        sprite.setScale(50.f / 270.f, 50.f / 263.f);
        break;

    case TypeObject::PlayerOne:
        sprite.setTextureRect(sf::IntRect(54, 458, 248, 266));
        sprite.setScale(50.f / 248.f, 50.f / 266.f);
        break;

    default:
        return sf::Sprite();
    }

    return sprite;
}

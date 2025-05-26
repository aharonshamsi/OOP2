#include "Tile.h"


Tile::Tile(const sf::Vector2f& location, ObjectType type)
    : m_location(location), m_type(type), m_visited(false)
{
    setSpriteByType();
}

void Tile::setSpriteByType()
{
    switch (m_type)
    {
    case ObjectType::Empty:
        m_picture = Images::getSprite(m_type, GameConsts::sizeTile);
        m_picture.setPosition(m_location);
        break;

    case ObjectType::Filled:
        m_picture = Images::getSprite(m_type, GameConsts::sizeTile);
        m_picture.setPosition(m_location);
        break;
    default:
        break;
    }
}

void Tile::setType(ObjectType type)
{
    m_type = type;
    m_picture.setTexture(Images::getTexture(type));
    m_picture.setPosition(m_location);
}

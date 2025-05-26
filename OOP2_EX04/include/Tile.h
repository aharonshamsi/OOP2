#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "Images.h"
#include "GameConsts.h"

enum class TileType {
    Empty,
    Filled,
    Frame,
    Trail
};


class Tile {

public:
    Tile(const sf::Vector2f& location, ObjectType type);
    virtual ~Tile() = default;

    sf::Vector2f getLocation() const { return m_location; }
    sf::Sprite getPicture() const { return m_picture; }
    ObjectType getType() const { return m_type; }

    bool getIsVisited() const { return m_visited; }
    void setVisited(bool visited) { m_visited = visited; }
    void setType(ObjectType type);
    void setSpriteByType();

protected:
    sf::Vector2f m_location;
    ObjectType m_type;
    sf::Sprite m_picture; 
    bool m_visited;
};


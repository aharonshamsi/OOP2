#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "Images.h"
#include "GameConsts.h"

enum class TileType {
    Empty, // ריק 
    Filled, // מלא 
    Frame,  // מסגרת
    Trail  //  שביל
};


class Tile {
public:
    Tile(const sf::Vector2f& location, ObjectType type);
    virtual ~Tile() = default;

    void setSpriteByType();
    sf::Vector2f getLocation() const { return m_location; }
    ObjectType getType() const { return m_type; }

    bool getIsVisited() const { return m_visited; }
    void setVisited(bool visited) { m_visited = visited; }
    void setType(ObjectType type);

    sf::Sprite getPicture() const { return m_picture; }

    //virtual sf::Color getColor() const = 0; // פונקציה שמחזירה צבע בהתאם לסוג האריח

protected:
    sf::Vector2f m_location;
    ObjectType m_type;
    sf::Sprite m_picture; // תמונה
    bool m_visited;
};


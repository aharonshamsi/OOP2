#pragma once
#include "GameObjectType.h"
#include "ImagesObject.h"
#include "ButtonData.h"
#include "State.h"


class Button {
public:
    Button(const GameObjectType& type, const sf::Vector2f& location, const sf::Vector2f& wantedSize);
    virtual ~Button() = default;

    bool isPressed(const sf::Vector2f& mousePos) const;
    virtual void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) = 0;

    void draw(sf::RenderWindow& window);

protected:
    GameObjectType m_type; // down
    sf::Sprite m_sprite;
    sf::Vector2f m_location;

    void updateSpritesForAll(const sf::Vector2f& wantedSize); // to movit
};

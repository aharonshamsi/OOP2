#pragma once
#include "GameObjectType.h"
#include "ImageMenu.h"
#include "ButtonData.h"
#include "State.h"


class Button {
public:
    Button(const sf::Vector2f& location);
    virtual ~Button() = default;

    bool isPressed(const sf::Vector2f& mousePos) const;
    virtual void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) = 0;

    void draw(sf::RenderWindow& window);

protected:
    sf::Sprite m_sprite;
    sf::Vector2f m_location;
};

#pragma once
#include "TypeButton.h"
#include "ImagesButtons.h"
#include "ButtonData.h"
#include "State.h"


class Button {
public:
    Button(const TypeButton& type, const sf::Vector2f& location, const sf::Vector2f& wantedSize);
    virtual ~Button() = default;

    bool isPressed(const sf::Vector2f& mousePos) const;
    virtual void handleClick(State& state, sf::RenderWindow& window, sf::Event& event) = 0;

    void draw(sf::RenderWindow& window);

protected:
    TypeButton m_type;
    sf::Sprite m_sprite;
    sf::Vector2f m_location;

    void updateSpritesForAll(const sf::Vector2f& wantedSize);
};

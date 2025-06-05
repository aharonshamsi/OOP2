#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameData.h"

class Background {

public:
	Background();

	void draw(sf::RenderWindow& window);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprint;
	sf::Vector2f m_location;
};
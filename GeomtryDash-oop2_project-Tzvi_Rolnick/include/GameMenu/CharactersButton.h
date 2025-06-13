#pragma once
#include "Button.h"

class CharactersButton : public Button
{
public:
	CharactersButton(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void scaleCharacters(const sf::Vector2f& wantedSize);
};


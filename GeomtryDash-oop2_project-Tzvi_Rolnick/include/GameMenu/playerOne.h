#pragma once
#include "GameMenu/CharactersButton.h"

#include "GameObject/Images/ImagesObject.h"
#include "GameObject/Images/TypeObject.h"

class PlayerOne : public CharactersButton {

public:
	PlayerOne(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	MenuAction handleClick(Info& info, sf::RenderWindow& window) override;

};
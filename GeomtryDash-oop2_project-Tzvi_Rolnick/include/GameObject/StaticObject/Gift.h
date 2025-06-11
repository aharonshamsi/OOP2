#pragma once

#include "GameObject/StaticObject/StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(sf::Vector2f location, sf::Sprite sprite);
	~Gift() override = default;
	virtual void handleCollision(Object&) override;
	
private:
	
};
#pragma once
#include "GameObject/Object.h"

Object::Object(sf::Vector2f location, sf::Sprite sprite)
	: m_location(location), m_sprite(sprite)
{
	m_sprite.setPosition(m_location);
}

void Object::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	window.draw(m_sprite);
}

bool Object::checkCollision(Object& other) const
{
	if (&other == this) 
		return false; // Avoid self-collision
	return true;
}

bool Object::collidesWith(Object& other) const
{
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}

void Object::moveByView(float& deltaTime)
{
	m_location.x += deltaTime * 150;
}
#pragma once
#include "component.h"
#include <SFML/System/Vector2.hpp>

class Moveable : public Component
{
public:
	Moveable(Entity& parent, float movementSpeed, float rotationSpeed);
	void move(sf::Vector2f direction, float deltaTime);
	void rotate(sf::Vector2f angle);
	
private:
	float movementSpeed;
	float rotationSpeed;
};


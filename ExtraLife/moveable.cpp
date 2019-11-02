#include "moveable.h"
#include "entity.h"
#include "transform.h"

Moveable::Moveable(Entity& parent, float movementSpeed, float rotationSpeed): Component(ComponentType::moveable, parent)
{
	this->movementSpeed = movementSpeed;
	this->rotationSpeed = rotationSpeed;
}

void Moveable::move(sf::Vector2f direction, float deltaTime)
{
	Transform** transform;
	if(entity.getComponent(ComponentType::transform, &transform))
	{
		(*transform)->move(direction * movementSpeed * deltaTime);
	}
}

void Moveable::rotate(sf::Vector2f angle)
{
}

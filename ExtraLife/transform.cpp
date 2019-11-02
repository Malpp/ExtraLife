#include "transform.h"
#include "componentType.h"

Transform::Transform(Entity& parent): Component(ComponentType::transform, parent)
{
}

Transform::Transform(Entity& parent, sf::Vector2f position, float angle): Component(ComponentType::transform, parent)
{
	this->transformable.setPosition(position);
	this->transformable.setRotation(angle);
}

void Transform::update(float deltaTime)
{
}

void Transform::setPosition(sf::Vector2f position)
{
	this->transformable.setPosition(position);
}

void Transform::setRotation(float angle)
{
	this->transformable.setRotation(angle);
}

void Transform::setScale(sf::Vector2f scale)
{
	transformable.setScale(scale);
}

sf::Vector2f Transform::getPosition()
{
	return transformable.getPosition();
}

float Transform::getRotation()
{
	return transformable.getRotation();
}

sf::Vector2f Transform::getScale()
{
	return transformable.getScale();
}

void Transform::move(sf::Vector2f direction)
{
	transformable.move(direction);
}

void Transform::rotate(float angle)
{
	transformable.rotate(angle);
}

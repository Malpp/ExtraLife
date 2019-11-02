#include "transform.h"
#include "componentType.h"

Transform::Transform(): Component(ComponentType::TRANSFORM)
{
}

Transform::Transform(sf::Vector2<float> position, float rotation): Component(ComponentType::TRANSFORM)
{
	this->position = position;
	this->rotation = rotation;
}

void Transform::update(float deltaTime)
{
}

void Transform::setPosition(sf::Vector2<float> position)
{
	this->position = position;
}

void Transform::setRotation(float rotation)
{
	this->rotation = rotation;
}

sf::Vector2<float> Transform::getPosition()
{
	return position;
}

float Transform::getRotation()
{
	return rotation;
}

void Transform::move(sf::Vector2<float> direction)
{
	position += direction;
}

void Transform::rotate(float rotation)
{
	this->rotation += rotation;
}

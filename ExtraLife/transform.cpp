#include "transform.h"
#include "componentType.h"
#include "shape.h"
#include "entity.h"

Transform::Transform(Entity& parent): Component(ComponentType::transform, parent)
{
}

Transform::Transform(Entity& parent, sf::Vector2f position, float angle): Component(ComponentType::transform, parent)
{
	this->transformable.setPosition(position);
	this->transformable.setRotation(angle);
	updateComponents();
}

void Transform::update(float deltaTime)
{
}

void Transform::setPosition(sf::Vector2f position)
{
	this->transformable.setPosition(position);
	updateComponents();
}

void Transform::setRotation(float angle)
{
	this->transformable.setRotation(angle);
	updateComponents();
}

void Transform::setScale(sf::Vector2f scale)
{
	transformable.setScale(scale);
	updateComponents();
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
	updateComponents();
}

void Transform::rotate(float angle)
{
	transformable.rotate(angle);
	updateComponents();
}

void Transform::updateComponents() const
{
	Shape* shape = nullptr;
	if(entity.getComponent(ComponentType::shape, shape))
	{
		shape->updateTransform(transformable);
	}
}

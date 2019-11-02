#include "shape.h"
#include <utility>

Shape::Shape(Entity& parent, sf::RectangleShape* shape): Component(ComponentType::shape, parent), shape(shape)
{
}

void Shape::draw(sf::RenderWindow* window)
{
	if (shape != nullptr)
	{
		window->draw(*shape);
	}
}

void Shape::updateTransform(const sf::Transformable& transformable)
{
	shape->setPosition(transformable.getPosition());
	shape->setRotation(transformable.getRotation());
	shape->setScale(transformable.getScale());
}

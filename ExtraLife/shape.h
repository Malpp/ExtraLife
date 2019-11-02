#pragma once
#include "component.h"
#include "transform.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Shape : public Component
{
public:
	Shape(Entity& parent, sf::RectangleShape* shape);
	void draw(sf::RenderWindow* window);
	
private:
	friend class Transform;
	void updateTransform(const sf::Transformable& transformable);
	sf::RectangleShape* shape;
};

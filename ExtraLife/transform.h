#pragma once
#include "component.h"
#include <SFML/System/Vector2.hpp>

class Transform : Component
{
public:
	Transform();
	Transform(sf::Vector2<float> position, float rotation);
	
	void update(float deltaTime) override;
	
	void setPosition(sf::Vector2<float> position);
	void setRotation(float rotation);

	sf::Vector2<float> getPosition();
	float getRotation();
	
	void move(sf::Vector2<float> direction);
	void rotate(float rotation);

private:
	sf::Vector2<float> position;
	float rotation;
};

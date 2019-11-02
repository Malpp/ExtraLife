#pragma once
#include "component.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Transform : public Component
{
protected:
	~Transform() = default;
public:
	Transform(Entity& parent);
	Transform(Entity& parent, sf::Vector2f position, float angle);
	
	void update(float deltaTime) override;
	
	void setPosition(sf::Vector2f position);
	void setRotation(float angle);
	void setScale(sf::Vector2f scale);

	sf::Vector2f getPosition();
	float getRotation();
	sf::Vector2f getScale();
	
	void move(sf::Vector2f direction);
	void rotate(float angle);

private:
	sf::Transformable transformable;
	void updateComponents() const;
};

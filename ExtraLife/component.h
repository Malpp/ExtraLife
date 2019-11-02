#pragma once
#include "componentType.h"

class Entity;

class Component
{
public:
	Component(ComponentType componentType, Entity& parent);

	ComponentType getType() const;

	virtual void update(float deltaTime);

protected:
	Entity& entity;
	ComponentType componentType;
	~Component() = default;
};

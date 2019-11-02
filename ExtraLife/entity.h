#pragma once
#include <map>
#include "componentType.h"
#include "component.h"
#include "entityType.h"

class Entity
{
public:
	Entity(EntityType entityType);

	void update(float deltaTime);

	bool addComponent(Component* component);
	bool removeComponent(ComponentType componentType);

	template<typename T>
	bool getComponent(ComponentType componentType, T* component);
	EntityType getType();

private:
	EntityType entityType;
	std::map<ComponentType, Component*> components;
};
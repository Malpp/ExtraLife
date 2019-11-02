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

	bool addComponent(Component& component);
	bool removeComponent(ComponentType componentType);
	
	Component getComponent(ComponentType componentType);
	EntityType getType() const;

private:
	EntityType entityType;
	std::map<ComponentType, Component, std::hash<int>> components;
	
	~Entity() = default;
};
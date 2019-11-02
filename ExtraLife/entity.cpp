#include "entityType.h"
#include "entity.h"

Entity::Entity(EntityType entityType): entityType(entityType)
{
}

void Entity::update(float deltaTime)
{
	for (auto& component : components)
	{
		component.second->update(deltaTime);
	}
}

bool Entity::addComponent(Component* component)
{
	if (!components.count(component->getType()))
	{
		components.emplace(component->getType(), component);
		return true;
	}
	return false;
}

bool Entity::removeComponent(ComponentType componentType)
{
	return components.erase(componentType);
}

EntityType Entity::getType()
{
	return entityType;
}

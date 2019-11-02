#include "componentType.h"
#include "component.h"

Component::Component(ComponentType componentType, Entity& parent): entity(parent), componentType(componentType)
{
}

void Component::update(float deltaTime)
{
}

ComponentType Component::getType() const
{
	return componentType;
}
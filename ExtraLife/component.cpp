#include "componentType.h"
#include "component.h"

Component::Component(ComponentType componentType): componentType(componentType)
{
}

void Component::update(float deltaTime)
{
}

ComponentType Component::getType() const
{
	return componentType;
}
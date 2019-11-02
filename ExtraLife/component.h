#pragma once

class Component
{
public:
	Component(ComponentType componentType);

	ComponentType getType() const;

	virtual void update(float deltaTime);

protected:
	const ComponentType componentType;
	~Component() = default;
};
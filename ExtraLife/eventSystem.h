#pragma once

class EventData;
enum class EventType;

class EventSystem
{
public:
	bool Subscribe(EventType eventType, EventData eventData);
private:
};

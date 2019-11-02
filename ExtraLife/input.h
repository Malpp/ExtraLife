#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Joystick.hpp>
#include <set>

class Input
{
private:
	static sf::Vector2f getAxis(sf::Joystick::Axis x, sf::Joystick::Axis y, unsigned int stick);
	static void playerJoined(unsigned int stick);
	static void checkIfPlayerJoined(unsigned int stick);
	static std::set<unsigned int> joined;
	static bool pressed[sf::Joystick::Count];
public:
	static void update();
	
	static sf::Vector2f getMovement(unsigned int stick);
	static sf::Vector2f getShoot(unsigned int stick);
	static bool getBomb(unsigned int stick);
};


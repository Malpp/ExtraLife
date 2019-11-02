#include "input.h"
#include <SFML/Graphics.hpp>
#include <iostream>

std::set<unsigned int> Input::joined;
bool Input::pressed[sf::Joystick::Count] = { false };

void Input::update()
{
	for (int i = 0; i < sf::Joystick::Count; ++i)
	{
		if (sf::Joystick::isConnected(i) && sf::Joystick::isButtonPressed(i, 7))
		{
			auto find = joined.find(i);
			if(find == joined.end())
			{
				joined.emplace(i);
				std::cout << "Player " << i << " joined!\n";
			}
			else
			{
				joined.erase(find);
				std::cout << "Player " << i << " left!\n";
			}
		}
	}
}

sf::Vector2f Input::getMovement(unsigned stick)
{
	return getAxis(sf::Joystick::X, sf::Joystick::Y, stick);
}

sf::Vector2f Input::getShoot(unsigned stick)
{
	return getAxis(sf::Joystick::U, sf::Joystick::V, stick);
}

bool Input::getBomb(unsigned stick)
{
	return sf::Joystick::isConnected(stick) && (sf::Joystick::isButtonPressed(stick, 4) || sf::Joystick::
		isButtonPressed(stick, 5));
}

sf::Vector2f Input::getAxis(sf::Joystick::Axis x, sf::Joystick::Axis y, unsigned stick)
{
	sf::Vector2f joystick(0, 0);

	if (sf::Joystick::isConnected(stick))
	{
		joystick.x = sf::Joystick::getAxisPosition(stick, x) / 100.f;
		joystick.y = sf::Joystick::getAxisPosition(stick, y) / 100.f;
	}

	return joystick;
}

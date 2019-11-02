#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
private:
	sf::RenderWindow window;
	
	void events();
public:
	void run();
	Game();
};


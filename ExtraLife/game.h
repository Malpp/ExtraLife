#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "entity.h"

class Game
{
private:
	sf::RenderWindow window;
	
	void events();
	void collision();
	void update(float deltaTime);
	void draw();
	
public:
	void run();
	Game();

	std::vector<Entity> entities;
};


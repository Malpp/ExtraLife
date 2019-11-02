#include "Game.h"
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "input.h"

void Game::events()
{
	sf::Event event{};
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			window.close();

		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::run()
{
	while (window.isOpen())
	{
		events();
		
		window.clear();
		Input::update();
		window.display();
	}
}

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Titlebar)
{
}

#include "game.h"
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "input.h"
#include "shape.h"
#include "moveable.h"

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

inline Entity CreateEntity(sf::Vector2f position)
{
	Entity entity = Entity(EntityType::character);
	entity.addComponent(new Shape(entity, new sf::RectangleShape(sf::Vector2f(10, 20))));
	entity.addComponent(new Transform(entity, position, 0));
	entity.addComponent(new Moveable(entity, 8, 30));

	return entity;
}

void Game::run()
{
	sf::Clock deltaClock;
	entities.push_back(CreateEntity(sf::Vector2f(100, 100)));
	
	while (window.isOpen())
	{
		events();
		
		window.clear();
		Input::update();

		update(deltaClock.restart().asSeconds());
		collision();
		draw();
		
		window.display();
	}
}

void Game::update(float deltaTime)
{
	for (Entity entity : entities)
	{
		entity.update(deltaTime);
	}
}

void Game::collision()
{
}

void Game::draw()
{
	for (Entity entity : entities)
	{
		Shape* shape = nullptr;
		if(entity.getComponent<Shape>(ComponentType::shape, &shape))
		{
			shape->draw(&window);
		}
	}
}

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Titlebar)
{
}

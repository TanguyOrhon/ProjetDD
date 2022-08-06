#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.h"
#include "Window.h"
#include "Map.h"


int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1920, 1080), "ProjetDD");
	window.setPosition(sf::Vector2i(0, 0));
	TileMap map("tiles/tileset.png", "tiles/map.txt", "tiles/map_collisions.txt", 25, 18);
	Window main_window(std::make_unique<Perso>("tanguy", "tiles/principal1.png"), window, map);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		main_window.step();
	}
	return 0;
}

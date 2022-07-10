#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.cpp"

int main()
{
	sf::Texture dragon;
	dragon.loadFromFile("tiles/dragon.png");
	sf::Sprite sprite_dragon(dragon);
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite_dragon);
		window.display();
	}

	return 0;
}
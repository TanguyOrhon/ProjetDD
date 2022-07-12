#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.h"
#include "Clavier.h"

int main()
{
	Personnage persoprincipal("tiles/principal1.png");
	sf::RenderWindow window(sf::VideoMode(1600, 900), "ProjetDD");
	window.setPosition(sf::Vector2i(0, 0));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		gestionclavier(persoprincipal);

		window.draw(persoprincipal.getSprite());
		window.display();
		window.clear();
	}

	return 0;
}
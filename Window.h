#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.h"


class Window {
public:
	Window(Personnage& perso, sf::RenderWindow& window);

	void setView();
	void draw();
	void step();

private:
	sf::View view_;
	sf::RenderWindow& window_;
	sf::Vector2f window_size_;
	Personnage& perso_;
};


#endif
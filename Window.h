#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.h"
#include "Map.h"


class Window {
public:
	Window(std::unique_ptr<Entity> perso, sf::RenderWindow& window, TileMap& map);

	void handle_event();
	void setView();
	void draw();
	void step();
	void anim_perso(float x, float y);

private:
	sf::View view_;
	sf::RenderWindow& window_;
	sf::Vector2f window_size_;
	std::unique_ptr<Entity> perso_;
	TileMap& map_;
};


#endif
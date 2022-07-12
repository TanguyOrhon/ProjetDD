#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.h"


class Window {
public:
	Window(Personnage& perso);

	void setView();
	bool getOpen() {
		return window_.isOpen();
	}
	bool GetPollEvent(sf::Event event) {
		return window_.pollEvent(event);
	}
	const sf::RenderWindow& getWindow_() const{
		return window_; 
	}
	void draw();
	void close();
	bool step();
	double deltatime();
	double elapsed() const;
	bool handle_event(double time);

	

private:
	sf::View view_;
	sf::RenderWindow window_;
	sf::Vector2f window_size_;
	Personnage& perso_;
	double start_{0}, end_{0};
};








#endif
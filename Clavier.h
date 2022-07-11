#ifndef CLAVIER_H
#define CLAVIER_H

#include <SFML/GRAPHICS.hpp>
#include <iostream>
#include "Personnages.h"

void gestionclavier(Personnage& perso) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		perso.setAnim_y(16);
		perso.animation();
		perso.move(0.0, 1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		perso.setAnim_y(246);
		perso.animation();
		perso.move(0.0, -1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		perso.setAnim_y(169);
		perso.animation();
		perso.move(1.0, 0.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		perso.setAnim_y(92);
		perso.animation();
		perso.move(-1.0, 0.0);
	}
}
#endif

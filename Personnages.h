#ifndef PERSONNAGES_H
#define PERSONNAGES_H
#include <SFML/GRAPHICS.hpp>
#include <iostream>

class Personnage {
public:
	Personnage(const char* texture);

	sf::Sprite getSprite() {
		return sprite_;
	}

	void setAnim_y(unsigned int dir) {
		anim_.y = dir;
	}

	void move(float x, float y);
	void animation(float x, float y);

private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	float x_, y_;
	float x_speed_, y_speed_;
	sf::Vector2u anim_;
	sf::Clock time;
	double fpsCount_ = 0, fps_ = 1000;
};


#endif
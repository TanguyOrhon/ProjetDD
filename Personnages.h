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
	sf::Vector2f getPosition() {
		return sf::Vector2f(x_, y_);
	}
	sf::Vector2u getSize() {
		return texture_.getSize();
	}
	void setAnim_y(unsigned int dir) {
		anim_.y = dir;
	}
	
	void move(float x, float y);
	void animation(float x, float y, double time);

private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	float x_, y_;
	float x_speed_, y_speed_;
	sf::Vector2u anim_;
	float fps_speed_{100}, fps_{0}, switchfps_{20};
	
};


#endif
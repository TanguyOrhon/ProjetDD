#ifndef PERSONNAGES_H
#define PERSONNAGES_H
#include <SFML/GRAPHICS.hpp>
#include <iostream>

class Entity {
public:
	Entity(const char* texture);
	virtual ~Entity() = default;

	sf::Sprite getSprite() {
		return sprite_;
	}
	sf::Vector2f getPosition() {
		return sf::Vector2f(x_, y_);
	}
	sf::Vector2u getSize() {
		return texture_.getSize();
	}
	sf::FloatRect getHitbox() {
		return hitbox_;
	}
	void setAnim_y(unsigned int dir) {
		anim_.y = dir;
	}

	void move(float x, float y);
	void animation(float x, float y);
	void handle_event();
	void collision(sf::FloatRect& otherhibox);

private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	float x_, y_;
	float x_speed_, y_speed_;
	sf::Vector2u anim_;
	sf::Clock clock_;
	float fps_;
	sf::FloatRect hitbox_;
};

class Monster : public Entity {
	Monster();
};

class Perso : public Entity {
public:
	Perso(std::string name, const char* texture) : Entity(texture), name_(name){};
private:
	std::string name_;
};
#endif
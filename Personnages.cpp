#include "Personnages.h"

Entity::Entity(const char* texture) :
	x_{ 0.0 },
	y_{ 0.0 },
	x_speed_{ 5.0 },
	y_speed_{ 5.0 },
	anim_{ 0,0 },
	fps_{ 0.0 }
{
	if (!texture_.loadFromFile(texture))
	{
		std::cout << "Pas de texture";
	}
	sprite_.setTexture(texture_);
	sprite_.setPosition(sf::Vector2f(x_, y_));
	sprite_.setTextureRect(sf::IntRect(0, 0, 32, 48));
	hitbox_ = sprite_.getGlobalBounds();
}

void Entity::move(float x, float y) {
	x_ = x_ + x * x_speed_;
	y_ = y_ + y * y_speed_;
	sprite_.setPosition(sf::Vector2f(x_, y_));
}

void Entity::animation(float x, float y) {
	if (clock_.getElapsedTime().asSeconds() - fps_ > 1.0 / 10) {
		fps_ = clock_.getElapsedTime().asSeconds();
		anim_.x += 32;
		if (anim_.x >= texture_.getSize().x) {
			anim_.x = 0;
		}
		sprite_.setTextureRect(sf::IntRect(anim_.x, anim_.y, 32, 48));
		move(x, y);
	}
}
void Entity::collision(sf::FloatRect& otherhibox) {
	if (hitbox_.intersects(otherhibox)) {
		std::cout<<"collision""\n";
	}
}
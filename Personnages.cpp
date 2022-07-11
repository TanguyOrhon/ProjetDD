#include "Personnages.h"

Personnage::Personnage(const char* texture) :
	texture_{},
	sprite_{},
	x_{ 200.0 },
	y_{ 200.0 },
	x_speed_{ 1.0 },
	y_speed_{ 1.0 },
	anim_{ 16,16 }
{
	if (!texture_.loadFromFile(texture))
	{
		std::cout << "Pas de texture";
	}
	sprite_.setTexture(texture_);
	sprite_.setPosition(sf::Vector2f(x_, y_));
	sprite_.setTextureRect(sf::IntRect(16, 16, 48, 64));
}

void Personnage::move(float x, float y) {
	x_ = x_ + x * x_speed_;
	y_ = y_ + y * y_speed_;
	sprite_.setPosition(sf::Vector2f(x_, y_));
}

void Personnage::animation() {
	anim_.x += 48;
	if (anim_.x >= texture_.getSize().x) {
		anim_.x = 20;
		std::cout <<texture_.getSize().y<<"\n";

	}
	sprite_.setTextureRect(sf::IntRect(anim_.x, anim_.y, 32, 64));
}
#include "Personnages.h"

Personnage::Personnage(const char* texture) :
	x_{ 200.0 },
	y_{ 200.0 },
	x_speed_{ 10.0 },
	y_speed_{ 10.0 },
	anim_{ 0,0 }
{
	if (!texture_.loadFromFile(texture))
	{
		std::cout << "Pas de texture";
	}
	sprite_.setTexture(texture_);
	sprite_.setPosition(sf::Vector2f(x_, y_));
	sprite_.setTextureRect(sf::IntRect(0, 0, 32, 48));
}

void Personnage::move(float x, float y) {
	x_ = x_ + x * x_speed_;
	y_ = y_ + y * y_speed_;
	sprite_.setPosition(sf::Vector2f(x_, y_));
}

void Personnage::animation(float x, float y, double time) {
	fps_ += fps_ + fps_speed_ * time;
	std::cout << "test" << time << "\n";
	if (fps_ >= switchfps_) {
		fps_ = 0;
		anim_.x += 32;
		if (anim_.x >= texture_.getSize().x) {
			anim_.x = 0;
		}
		sprite_.setTextureRect(sf::IntRect(anim_.x, anim_.y, 32, 48));
		move(x, y);
	}


}
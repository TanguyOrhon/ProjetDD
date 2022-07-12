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
	sprite_.setTextureRect(sf::IntRect(0, 0, 32, 48));
}

void Personnage::move(float x, float y) {
	x_ = x_ + x * x_speed_;
	y_ = y_ + y * y_speed_;
	sprite_.setPosition(sf::Vector2f(x_, y_));
}

void Personnage::animation(float x, float y) {
	fpsCount_ += fps_ * 0.5*time.restart().asSeconds();
	if (fpsCount_ >= fps_) {
		anim_.x += 32;
		if (anim_.x >= texture_.getSize().x) {
			anim_.x = 0;
		}
		sprite_.setTextureRect(sf::IntRect(anim_.x, anim_.y, 32, 48));
		move(x, y);
	}


}
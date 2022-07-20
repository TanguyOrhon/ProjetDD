#include "Personnages.h"

Personnage::Personnage(const char* texture) :
	x_{ 200.0 },
	y_{ 200.0 },
	x_speed_{ 5.0 },
	y_speed_{ 5.0 },
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

void Personnage::animation() {

	anim_.x += 32;
	if (anim_.x >= texture_.getSize().x) {
		anim_.x = 0;
	}
	sprite_.setTextureRect(sf::IntRect(anim_.x, anim_.y, 32, 48));
}

void Personnage::handle_event()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setAnim_y(0);
		animation();
		move(0.0, 1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setAnim_y(144);
		animation();
		move(0.0, -1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setAnim_y(96);
		animation();
		move(1.0, 0.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setAnim_y(48);
		animation();
		move(-1.0, 0.0);
	}
}
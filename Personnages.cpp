#include "Personnages.h"

Personnage::Personnage(const char* texture) :
	x_{ 200.0 },
	y_{ 200.0 },
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

void Personnage::move(float x, float y) {
	x_ = x_ + x * x_speed_;
	y_ = y_ + y * y_speed_;
	sprite_.setPosition(sf::Vector2f(x_, y_));
}

void Personnage::animation(float x, float y) {
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

void Personnage::handle_event()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setAnim_y(0);
		animation(0.0, 1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setAnim_y(144);
		animation(0.0, -1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setAnim_y(96);
		animation(1.0, 0.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setAnim_y(48);
		animation(-1.0, 0.0);
	}
}

void Personnage::collision(sf::FloatRect& otherhibox) {
	if (hitbox_.intersects(otherhibox)) {
		std::cout<<"collision""\n";
	}
}
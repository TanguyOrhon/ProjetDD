#include "Window.h"


Window::Window(std::unique_ptr<Entity> perso, sf::RenderWindow& window, TileMap& map) :
	perso_{ std::move(perso) },
	map_{map},
	window_{ window }
{
	window_size_ = sf::Vector2f(window_.getSize());
};
void Window::setView() {
	float position_x = perso_->getPosition().x + (float(perso_->getSize().x) / 2) - (window_size_.x / 2);
	float position_y = perso_->getPosition().y + (float(perso_->getSize().y) / 2) - (window_size_.y / 2);
	view_.reset(sf::FloatRect(position_x, position_y, window_size_.x, window_size_.y));
	window_.setView(view_);
}

void Window::draw() {
	setView();
	window_.draw(map_);
	window_.draw(perso_->getSprite());
}

void Window::step()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window_.close();
	}
	perso_->handle_event();
	draw();
	window_.display();
	window_.clear();
}
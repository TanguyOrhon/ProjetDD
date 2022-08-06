#include "Window.h"


Window::Window(std::unique_ptr<Entity> perso, sf::RenderWindow& window, TileMap& map) :
	perso_{ std::move(perso) },
	map_{ map },
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
	handle_event();
	draw();
	window_.display();
	window_.clear();
}

void Window::anim_perso(float x, float y)
{
	sf::Vector2f pos = perso_->getPosition();
	sf::Vector2u size = perso_->getSize();
	sf::Vector2f speed = perso_->getSpeed();
	int x_collide = int(pos.x / size.x + x * speed.x);
	int y_collide = int(pos.y / size.y + y * speed.y);
	int test = map_.get_level_collide(x_collide, y_collide);
	if (test == 0) {
		perso_->animation(x, y);
		std::cout << x_collide << "," << y_collide << "\n";
	}
}
void Window::handle_event()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		perso_->setAnim_y(0);
		//perso_->animation(0.0, 1.0);
		anim_perso(0.0, 1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		perso_->setAnim_y(144);
		anim_perso(0.0, -1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		perso_->setAnim_y(96);
		anim_perso(1.0, 0.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		perso_->setAnim_y(48);
		anim_perso(-1.0, 0.0);
	}
}

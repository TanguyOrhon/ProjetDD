#include "Window.h"


Window::Window(std::unique_ptr<Entity> perso, sf::RenderWindow& window, TileMap& map) :
	perso_{ std::move(perso) },
	map_{ map },
	window_{ window }
{
	window_size_ = sf::Vector2f(window_.getSize());
};
void Window::setView() {
	float position_x = perso_->getPosition().x + (float(perso_->getSize().width) / 2) - (window_size_.x / 2);
	float position_y = perso_->getPosition().y + (float(perso_->getSize().height) / 2) - (window_size_.y / 2);
	view_.reset(sf::FloatRect(position_x, position_y, window_size_.x, window_size_.y));
	window_.setView(view_);
}

void Window::draw() {
	setView();
	window_.draw(map_);

	map_.debug_collide();
	for (int i = 0; i < 450; i++) {
		window_.draw(map_.get_Debug_Collide(i));
	}
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
	sf::FloatRect size = perso_->getSize();
	sf::Vector2f speed = perso_->getSpeed();
	std::cout << size.width << ',' << size.height << '\n';
	float x_collide = (pos.x + x * speed.x - size.width / 2) / 64;
	float y_collide = (pos.y + y * speed.y + size.height / 4) / 64;
	//std::cout << x_collide << "," << y_collide << "\n" << round(x_collide) << "," << round(y_collide) << "\n";	
	int test = map_.get_level_collide(round(x_collide), round(y_collide));
	if (test == 0) {
		perso_->animation(x, y);
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

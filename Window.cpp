#include "Window.h"
#include <chrono>

Window::Window(Personnage& perso) :
	perso_{ perso }
{
	window_.create(sf::VideoMode(1920, 1080), "ProjetDD");
	window_size_ = sf::Vector2f(window_.getSize());
	window_.setPosition(sf::Vector2i(0, 0));
};
void Window::setView() {
	float position_x = perso_.getPosition().x + (float(perso_.getSize().x) / 2) - (window_size_.x / 2);
	float position_y = perso_.getPosition().y + (float(perso_.getSize().y) / 2) - (window_size_.y / 2);
	view_.reset(sf::FloatRect(position_x, position_y, window_size_.x, window_size_.y));
	window_.setView(view_);
}

void Window::draw() {
	setView();
	window_.draw(perso_.getSprite());
}

void Window::close() {
	window_.close();
}

bool
Window::step()
{
	if (!window_.isOpen())
	{
		return false;
	}
	const double time = deltatime();

	draw();
	window_.display();
	window_.clear();
	return handle_event(time);
}
double
Window::deltatime()
{
	const auto clock_now = std::chrono::system_clock::now().time_since_epoch();
	const auto now = 1e-3 * double(std::chrono::duration_cast
		<std::chrono::milliseconds>(clock_now).count());
	if (start_ <= 0.0)
	{
		start_ = end_ = now;
	}
	const auto dt = now - end_;
	end_ += dt;
	const auto step = 1.0 / 30.0; // target 30 FPS
	if (dt < step)
	{
		sf::sleep(sf::seconds(float(step - dt)));
	}
	return dt;
}

double Window::elapsed() const
{
	return end_ - start_;
}

bool // go on
Window::handle_event(double time)
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			window_.close();
			return false;
		}

		case sf::Event::MouseButtonPressed:
		{
			/*if (event.mouseButton.button == sf::Mouse::Left)
			{
				const auto coord = render_window_.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				click_all_(coord.x, coord.y);
				std::cout << '[' << name_ << "] left button at ("
					<< coord.x << "," << coord.y << ")\n";

				// ...

			}*/
			break;
		}
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
			{
				window_.close();
				return false;
			}
			case sf::Keyboard::Left:
			{
				perso_.setAnim_y(48);
				perso_.animation(-1.0, 0.0, time);
				break;
			}
			case sf::Keyboard::Right:
			{
				perso_.setAnim_y(96);
				perso_.animation(1.0, 0.0, time);
				break;
			}
			case sf::Keyboard::Up:
			{
				perso_.setAnim_y(144);
				perso_.animation(0.0, -1.0, time);
				break;
			}
			case sf::Keyboard::Down:
			{
				perso_.setAnim_y(0);
				perso_.animation(0.0, 1.0, time);
				break;
			}
			case sf::Keyboard::A:
			{
				std::cout << "A\n";
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return true;
}
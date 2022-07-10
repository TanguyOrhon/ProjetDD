#include <SFML/GRAPHICS.hpp>
#include <iostream>

class Personnage {
public:
	Personnage(const char* texture) :
		texture_{},
		sprite_texture_{}
	{
		if (!texture_.loadFromFile(texture))
		{
			std::cout << "Pas de texture";
		}
		sprite_texture_.setTexture(texture_);
	}

	sf::Sprite getSprite() {
		return sprite_texture_;
	}

private:
	sf::Texture texture_;
	sf::Sprite sprite_texture_;

};

#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap(const char* tileset, const char* map, const char* mapcollide, unsigned int width, unsigned int height);
	bool load(const int* tiles);
	std::vector<std::string> explode(std::string const& s, char delim);
	void create_level();
	void create_collide();
	int get_level_collide(int i, int y) {
		return level_collide_[i + y * 25];
	}
	sf::RectangleShape get_Debug_Collide(int i) {
		return debug_collide_[i];
	}
	void debug_collide();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices_;
	sf::Texture m_tileset_;
	unsigned int width_, height_;
	sf::Vector2f tileSize_;
	sf::Vector2f sizeMap_;
	std::ifstream map_;
	std::ifstream map_collide_;
	int level_collide_[450];
	sf::RectangleShape debug_collide_[450];
};




#endif
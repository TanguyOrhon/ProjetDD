#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap(const char* tileset, const char* tiles, unsigned int width, unsigned int height);
	bool load(const int* tiles);
	std::vector<std::string> explode(std::string const& s, const char* delim);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices_;
	sf::Texture m_tileset_;
	unsigned int width_, height_;
	sf::Vector2u tileSize_;
};




#endif
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
	TileMap(const char* tileset, const char* tiles);
	bool load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	std::vector<std::string> explode(std::string const& s, char delim);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices_;
	sf::Texture m_tileset_;
};




#endif
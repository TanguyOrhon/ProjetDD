#include "Map.h"


TileMap::TileMap(const char* tileset, const char* tiles) 
{
	if (!m_tileset_.loadFromFile(tileset)) {
		std::cout << "Pas de tileset";
	}
	std::ifstream tiles_(tiles);
	std::string content_(std::istreambuf_iterator<char>(tiles_), std::istreambuf_iterator<char>());
}

bool TileMap::load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
	// on charge la texture du tileset

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices_.setPrimitiveType(sf::Quads);
	m_vertices_.resize(width * height * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// on récupère le numéro de tuile courant
			int tileNumber = tiles[i + j * width];

			// on en déduit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset_.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset_.getSize().x / tileSize.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices_[(i + j * width) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &m_tileset_;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices_, states);
}


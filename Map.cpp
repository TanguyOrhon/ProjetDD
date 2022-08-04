#include "Map.h"

TileMap::TileMap(const char* tileset, const char* maptxt, unsigned int width, unsigned int height) :
	width_{ std::move(width) },
	height_{ std::move(height) },
	tileSize_{ 32.0,32.0 },
	tiles_(maptxt)
{
	if (!m_tileset_.loadFromFile(tileset)) {
		std::cout << "Pas de tileset";
	}
	create_level();
}
void TileMap::create_level() {
	std::string content_((std::istreambuf_iterator<char>(tiles_)), (std::istreambuf_iterator<char>()));
	auto str = explode(content_, ' ');
	int level[450] = {};
	int i = 0;
	for (const std::string s : str) {
		i += 1;
		level[i] = std::stoi(s);
	}
	load(level);
}
std::vector<std::string> TileMap::explode(std::string const& s, char delim)
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim);)
	{
		result.push_back(token);
		std::cout << token << "\n";
	}
	return result;
}

bool TileMap::load(const int* tiles) {
	// on charge la texture du tileset

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices_.setPrimitiveType(sf::Quads);
	m_vertices_.resize(width_ * height_ * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width_; ++i)
	{
		for (unsigned int j = 0; j < height_; ++j)
		{

			// on récupère le numéro de tuile courant
			int tileNumber = tiles[i + j * width_];

			// on en déduit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset_.getSize().x / int(tileSize_.x));
			int tv = tileNumber / (m_tileset_.getSize().x / int(tileSize_.x));

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices_[(i + j * width_) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize_.x, j * tileSize_.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize_.x, j * tileSize_.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize_.x, (j + 1) * tileSize_.y);
			quad[3].position = sf::Vector2f(i * tileSize_.x, (j + 1) * tileSize_.y);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize_.x, tv * tileSize_.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize_.x, tv * tileSize_.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize_.x, (tv + 1) * tileSize_.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize_.x, (tv + 1) * tileSize_.y);
		}
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


/**
 * @file tilemap.hpp
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe qui crée la map graphique
**/

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @class TileMap tilemap.hpp
 *
 * @brief Affichage d'une map
 */
class TileMap : public sf::Drawable, public sf::Transformable
{
	private:
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<std::vector<unsigned int>> tiles, unsigned int width, unsigned int height);
		
};

#endif //TILEMAP_HPP

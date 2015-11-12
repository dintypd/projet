/**
 * @file tilemap.h
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe qui crée la map graphique
**/

#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>


/**
 * @class TileMap tilemap.h
 *
 * @brief Affichage d'une map
 */
class TileMap
{
	private:
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
		
}

#endif //TILEMAP_H

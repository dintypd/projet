/**
 * @file path.h
 * @author A. Perhirin B. Le Clère
 * @date 6/10/2015
 * @brief definition de la classe Path
**/

#ifndef PATH_H
#define PATH_H

#include "position.h"

#include <vector>

/**
 * @class Path
 * 
 * @brief Classe implémentant un chemin (path) sur la map
 *
 **/
class Path
{
	private:
		std::vector<Position> _path; // tableau de position : la path
		
	public:
		
		/**
		 * @brief ajoute une position au vector
		**/		
		void pushPos(Position pos);
		
		/**
		 * @brief retire une position au vector
		 * @return la position retirée
		**/
		Position popPos();
		
		/**
		 * @brief accesseur des éléments du vector
		 * @return la position à l'indice i
		 */
		Position getPosition(unsigned int i) const;
		
		/**
		 * @brief calcule la taille du vector
		 * @return la taille de _path
		 */
		unsigned int size() const;
		
		/**
		 * @brief redéfinition de l'accesseur aux case du tableau
		 */
		Position operator[](unsigned int const & i);
};

#endif // PATH_H

/**
 * @file path.h
 * @author A. Perhirin B. Le Clère
 * @date 6/10/2015
 * @brief definition de la classe Path
**/

#ifndef PATH_H
#define PATH_H

#include <vector>
#include "position.h"

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
		// méthodes
		
		/**
		 * @brief Constructeur, crée une path
		**/		
		Path();
		
		/**
		 * @brief ajoute une position a la file
		**/		
		void pushPos(Position pos);
		
		/**
		 * @brief retire une position a la file 
		 * @return la position retirée
		**/
		Position popPos();
		
		/**
		 * @brief calcule la taille de la file
		 * @return la taille de _path
		 */
		unsigned int size() const;
		
		Position operator[](unsigned int const & i);
};

#endif

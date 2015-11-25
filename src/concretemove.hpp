/**
 * @file concretemove.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition du mouvement
**/

#ifndef CONCRETE_MOVE_HPP
#define CONCRETE_MOVE_HPP

#include "move.hpp"

class Map;
class Path;
class Unit;

/**
 * @class ConcreteMove conretemove.h
 * 
 * @brief Classe concrete définissant le comportement de déplacement des unités mouvantes
 */
class ConcreteMove : public Move
{
	public:
		/**
		 * @brief déplacement d'une unité
		 * @param path un chemin
		 * @param map une map
		 * @param u une unité
		 */
		void move(Path* path, Map* map, Unit* u);
};

#endif // CONCRETE_MOVE_HPP

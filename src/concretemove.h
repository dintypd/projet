/**
 * @file concretemove.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition du mouvement
**/

#ifndef CONCRETE_MOVE_H
#define CONCRETE_MOVE_H

#include "move.h"

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
		void move(Path* path, Map* map, Unit* u);
};

#endif // CONCRETE_MOVE_H

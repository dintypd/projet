/**
 * @file concretenomove.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition du non mouvement
**/

#ifndef CONCRETE_NO_MOVE_H
#define CONCRETE_NO_MOVE_H

#include "move.h"

class Path;
class Map;
class Unit;
/**
 * @class ConcreteNoMove concretenomove.h
 * 
 * @brief Classe concrete définissant le comportement de déplacement des unités immobiles
 */
class ConcreteNoMove
{
	public:
		void move(Path* path, Map* map, Unit* u);
};

#endif // CONCRETE_NO_MOVE_H

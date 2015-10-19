/**
 * @file move.h
 * @author B. Le Clère, A. Perhirin
 * @since 05/10/2015
 * @brief Définition des stratégies de déplacement
**/

#ifndef MOVE_H
#define MOVE_H

#include "path.h"

class Map;

/**
 * @class Move move.h
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * de déplacements selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class Move
{
	public:
		virtual void move(Path path, Map map) = 0;
};

/**
 * @class ConcreteMove move.h
 * 
 * @brief Classe concrete définissant le comportement de déplacement des unités mouvantes
 */
class ConcreteMove
{
	public:
		void move(Path path, Map map);
};

/**
 * @class ConcreteNoMove move.h
 * 
 * @brief Classe concrete définissant le comportement de déplacement des unités immobiles
 */
class ConcreteNoMove
{
	public:
		void move(Path path, Map map);
};

#endif // MOVE_H

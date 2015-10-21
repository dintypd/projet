/**
 * @file move.h
 * @author B. Le Clère, A. Perhirin
 * @since 05/10/2015
 * @brief Définition des stratégies de déplacement
**/

#ifndef MOVE_H
#define MOVE_H


class Path;
class Map;
class Unit;

/**
 * @class Move move.h
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * de déplacements selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class Move
{
	public:
		virtual void move(Path* path, Map* map, Unit* u) = 0;
};

#endif // MOVE_H

/**
 * @file move.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 05/10/2015
 * @brief Définition des stratégies de déplacement
**/

#ifndef MOVE_HPP
#define MOVE_HPP

class Path;
class Map;
class Unit;

/**
 * @class Move move.hpp
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * de déplacements selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class Move
{
	public:
		/**
		 * @brief Destructeur (évite les warnings)
		 */
		//virtual ~Move();
	
		/**
		 * @brief méthode virtuelle pure de déplacement d'une unité
		 * @param path un chemin
		 * @param map une map
		 * @param u une unité
		 */
		virtual void move(Path* path, Map* map, Unit* u) = 0;
};

#endif // MOVE_HPP

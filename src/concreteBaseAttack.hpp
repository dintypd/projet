/**
 * @file concreteBaseAttack.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base normale
**/

#ifndef CONCRETE_BASE_ATTACK_HPP
#define CONCRETE_BASE_ATTACK_HPP

#include "attack.hpp"

class Position;
class Map;
class Unit;

/**
 * @class ConcreteBaseAttack concreteBaseAttack.hpp
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités normales
 */
class ConcreteBaseAttack : public Attack
{
	public:
		/**
		 * @brief Constructeur
		 */
		ConcreteBaseAttack(unsigned int ap);
		
		/**
		 * @brief Méthode d'attaque
		 * @param position une position
		 * @param map une map
		 * @param attacker l'unité qui attaque
		 */
		void attack(Position position, Map* map, Unit* attacker);
};

#endif // CONCRETE_BASE_ATTACK_HPP

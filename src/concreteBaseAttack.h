/**
 * @file concreteBaseAttack.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base
**/

#ifndef CONCRETE_BASE_ATTACK_H
#define CONCRETE_BASE_ATTACK_H

#include "attack.h"

class Position;
class Map;
class Unit;
/**
 * @class ConcreteBaseAttack concreteBaseAttack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités normales
 */
class ConcreteBaseAttack : public Attack
{
	public:
		ConcreteBaseAttack(unsigned int ap);
		void attack(Position position, Map* map, Unit* attacker);
};

#endif

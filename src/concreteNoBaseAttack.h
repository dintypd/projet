/**
 * @file concreteNoBaseAttack.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base pour les unités qui n'attaquent pas
**/

#ifndef CONCRETE_NO_BASE_ATTACK_H
#define CONCRETE_NO_BASE_ATTACK_H

#include "attack.h"

class Position;
class Map;
class Unit;
/**
 * @class ConcreteNoBaseAttack concreteNoBaseAttack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités qui n'attaquent pas
 */
class ConcreteNoBaseAttack : public Attack
{
	public:
		ConcreteNoBaseAttack(unsigned int ap);
		void attack(Position position, Map* map, Unit* attacker);
};

#endif


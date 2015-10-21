/**
 * @file concreteBaseAttack.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base
**/

#ifndef CONCRETE_BASE_ATTACK_H
#define CONCRETE_BASE_ATTACK_H

#include "attack.h"
#include "position.h"

class Map;
/**
 * @class ConcreteBaseAttack concreteBaseAttack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités normales
 */
class ConcreteBaseAttack : Attack
{
	public:
		void attack(Position position, Map* map, unsigned int dmgs);
};

#endif

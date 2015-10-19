/**
 * @file concreteBaseAttack.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition del'attaque de base
**/

#ifndef CONCRETE_BASE_ATTACK_H
#define CONCRETE_BASE_ATTACK_H

#include "position.h"
#include "attack.h"

class Map;
/**
 * @class ConcreteBaseAttack attack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités normales
 */
class ConcreteBaseAttack : Attack
{
	public:
		void attack(Position position, Map* map);
};

#endif

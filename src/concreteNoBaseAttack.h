/**
 * @file concreteNoBaseAttack.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base pour les unités qui n'attaquent pas
**/

#ifndef CONCRETE_NO_BASE_ATTACK_H
#define CONCRETE_NO_BASE_ATTACK_H

#include "position.h"
#include "attack.h"

class Map;
/**
 * @class ConcreteNoBaseAttack concreteNoBaseAttack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités qui n'attaquent pas
 */
class ConcreteNoBaseAttack : Attack
{
	public:
		void attack(Position position, Map* map);
};

#endif


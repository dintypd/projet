/**
 * @file concreteBaseAttackSpeTower.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base pour les unités spécialisées dans l'attaque de tours
**/

#ifndef CONCRETE_BASE_ATTACK_SPE_TOWER_H
#define CONCRETE_BASE_ATTACK_SPE_TOWER_H

#include "attack.h"

class Map;
class Unit;
class Position;
/**
 * @class ConcreteBaseAttackSpeTower concreteBaseAttackSpeTower.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités spécialisées dans l'attaque de tours
 */
class ConcreteBaseAttackSpeTower : public Attack
{
	public:
		void attack(Position position, Map* map, unsigned int dmgs);
};

#endif


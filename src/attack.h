/**
 * @file attack.h
 * @author B. Le Clère, A. Perhirin
 * @since 05/10/2015
 * @brief Définition des stratégies d'attaque
**/

#ifndef ATTACK_H
#define ATTACK_H
#include "position.h"

class Map;
class Unit;
/**
 * @class Attack attack.h
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * d'attaque selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class Attack
{
	public:
		virtual void attack(Position position, Map* map) = 0;
};

/**
 * @class ConcreteBaseAttackSpeTower attack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités spécialisées dans l'attaque de tours
 */
/*class ConcreteBaseAttackSpeTower : Attack
{
	public:
		void attack(Position position, Map* map);
};*/

/**
 * @class ConcreteNoBaseAttack attack.h
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités passives
 */
/*class ConcreteNoBaseAttack : Attack
{
	public:
		void attack(Position position, Map map);
};*/
 
#endif // ATTACK_H


/**
 * @file concreteBaseAttackSpeBase.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de l'attaque de base pour les unité puissante sur les bases
**/

#ifndef CONCRETE_BASE_ATTACK_SPE_BASE_HPP
#define CONCRETE_BASE_ATTACK_SPE_BASE_HPP

#include "attack.hpp"

class Position;
class Map;
class Unit;
/**
 * @class ConcreteBaseAttack concreteBaseAttack.hpp
 * 
 * @brief Classe concrete définissant le comportement d'attaque de base des unités normales
 */
class ConcreteBaseAttackSpeBase : public Attack
{
	public:
		ConcreteBaseAttackSpeBase(unsigned int ap);
		void attack(Position position, Map* map, Unit* attacker);
};

#endif // CONCRETE_BASE_ATTACK_SPE_BASE_HPP


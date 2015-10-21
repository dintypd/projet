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
/**
 * @class Attack attack.h
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * d'attaque selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class Attack
{
	public:
		virtual void attack(Position position, Map* map, unsigned int dmgs) = 0;
};

 
#endif // ATTACK_H


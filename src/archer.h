/**
 * @file archer.h
 * @author B. Le Clère, A. Perhirin
 * @since 09/11/2015
 * @brief Définition de la classe Archer
**/

#ifndef ARCHER_H
#define ARCHER_H

#include "unit.h"

/**
 * @class Archer archer.h
 * 
 * @brief Classe définissant un archer
 */
class Archer : public Unit
{
	public:
		Archer( unsigned int range,
				unsigned int ap,
				unsigned int mp,
				unsigned int hp,
				unsigned int dmgs,
				unsigned int cost,
				Attack* attack,
				HPLoss* hpLoss,
				Move* move,
				Position position);
				
		std::string classe();
		
		Unit* clone(Position position);
		
		void afficherInfos();
};

#endif // KNIGHT_H


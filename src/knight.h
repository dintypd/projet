/**
 * @file knight.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Knight
**/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "unit.h"

/**
 * @class Knight knight.h
 * 
 * @brief Classe définissant un chevalier
 */
class Knight : public Unit
{
	public:
		Knight( unsigned int range,
				unsigned int ap,
				unsigned int mp,
				unsigned int hp,
				unsigned int dmgs,
				unsigned int cost,
				Attack* attack,
				HPLoss* hpLoss,
				Move* move,
				Position position,
				String image);
				
		std::string classe();
		
		Unit* clone(Position position);
		
		void afficherInfos();
};

#endif // KNIGHT_H

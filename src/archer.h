/**
 * @file archer.h
 * @author B. Le Clère, A. Perhirin
 * @since 09/11/2015
 * @brief Définition de la classe Archer
**/

#ifndef ARCHER_H
#define ARCHER_H

#include "unit.h"

#include <string>

/**
 * @class Archer archer.h
 * 
 * @brief Classe définissant un archer
 */
class Archer : public Unit
{
	public:
		/**
		 * @brief Constructeur
		 */
		Archer(unsigned int range,
			   unsigned int ap,
			   unsigned int mp,
			   unsigned int hp,
			   unsigned int dmgs,
			   unsigned int cost,
			   Attack* attack,
			   HPLoss* hpLoss,
			   Move* move,
			   Position position,
			   std::string image);
		
		/**
		 * @brief Accesseur de la classe
		 * @return "archer"
		 */
		std::string classe() const;
		
		/**
		 * @brief construit un archer identique à la position donnée
		 * @param position une position
		 * @return un archer
		 */
		Unit* clone(Position position) const;
		
		/**
		 * @brief affiche les différentes informations sur l'archer
		 */
		void afficherInfos() const;
};

#endif // ARCHER_H


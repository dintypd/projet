/**
 * @file knight.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Knight
**/

#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include "unit.h"

/**
 * @class Knight knight.h
 * 
 * @brief Classe définissant un chevalier
 */
class Knight : public Unit
{
	public:
		/**
		 * @brief Constructeur
		 */
		Knight(unsigned int range,
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
		 * @return "knight"
		 */	
		std::string classe() const;
		
		/**
		 * @brief construit un knight identique à la position donnée
		 * @param position une position
		 * @return un knight
		 */
		Unit* clone(Position position) const;
		
		/**
		 * @brief affiche les différentes informations sur l'archer
		 */
		void afficherInfos() const;
};

#endif // KNIGHT_H

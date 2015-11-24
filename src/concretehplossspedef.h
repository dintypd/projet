/**
 * @file concretehplossspedef.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de la perte d'HP d'une unité défensive
**/

#ifndef CONCRETE_HP_LOSS_SPE_DEF_H
#define CONCRETE_HP_LOSS_SPE_DEF_H

#include "hploss.h"

class Unit;
class Base;

/**
 * @class ConcreteConcreteHPLossSpeDef concretehplossspedef.h
 * 
 * @brief Classe concrete définissant le comportement de la perte de point de vie des unités défensives
 */
class ConcreteHPLossSpeDef : public HPLoss
{
	public:
		/**
		 * @brief Perte d'hp des unité
		 * @param value un entier positif
		 * @param u l'unité qui prend des dégats
		 */
		void hpLoss(unsigned int value, Unit* u);
		
		/**
		 * @brief Perte d'hp des bases
		 * @param value un entier positif
		 * @param b la base qui prend des dégats
		 */
		void hpLoss(unsigned int value, Base* b);
};

#endif // CONCRETE_HP_LOSS_SPE_DEF_H

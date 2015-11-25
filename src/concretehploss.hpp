/**
 * @file concretehploss.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de la perte d'HP de base
**/

#ifndef CONCRETE_HP_LOSS_HPP
#define CONCRETE_HP_LOSS_HPP

#include "hploss.hpp"

class Unit;
class Base;

/**
 * @class ConcreteConcreteHPLoss concretehploss.hpp
 * 
 * @brief Classe concrete définissant le comportement de la perte de point de vie des unités normales
 */
class ConcreteHPLoss : public HPLoss
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

#endif // CONCRETE_HP_LOSS_HPP

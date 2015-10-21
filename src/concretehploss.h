/**
 * @file concretehploss.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de la perte d'HP de base
**/

#ifndef CONCRETE_HP_LOSS_H
#define CONCRETE_HP_LOSS_H

#include "hploss.h"

class Unit;
/**
 * @class ConcreteConcreteHPLoss concretehploss.h
 * 
 * @brief Classe concrete définissant le comportement de la perte de point de vie des unités normales
 */
class ConcreteHPLoss : HPLoss
{
	public:
		void hpLoss(unsigned int value, Unit* u);
};

#endif // CONCRETE_HP_LOSS_H

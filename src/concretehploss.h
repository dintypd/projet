/**
 * @file concretehploss.h
 * @author B. Le Clère, A. Perhirin
 * @since 19/10/2015
 * @brief Définition de la perte d'HP de base
**/

#ifndef CONCRETE_HP_LOSS_H
#define CONCRETE_HP_LOSS_H

#include "hploss.h"

class Attackable;

/**
 * @class ConcreteConcreteHPLoss concretehploss.h
 * 
 * @brief Classe concrete définissant le comportement de la perte de point de vie des unités normales
 */
class ConcreteHPLoss : public HPLoss
{
	public:
		void hpLoss(unsigned int value, Attackable* attacked);
};

#endif // CONCRETE_HP_LOSS_H

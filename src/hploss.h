/**
 * @file hploss.h
 * @author B. Le Clère, A. Perhirin
 * @since 05/10/2015
 * @brief Définition du comportement de la perte d'HP
**/

#ifndef HPLOSS_H
#define HPLOSS_H

class Unit;
class Base;

/**
 * @class HPLoss hploss.h
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * de la perte de points de vie selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class HPLoss
{
	public:
		virtual void hpLoss(unsigned int value, Unit* u) = 0;
		virtual void hpLoss(unsigned int value, Base* b) = 0;
};


#endif // HPLOSS_H

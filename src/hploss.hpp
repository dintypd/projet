/**
 * @file hploss.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 05/10/2015
 * @brief Définition du comportement de la perte d'HP
**/

#ifndef HPLOSS_HPP
#define HPLOSS_HPP

class Unit;
class Base;

/**
 * @class HPLoss hploss.hpp
 * 
 * @brief Classe virtuelle pure permettant l'utilisation de différents comportement
 * de la perte de points de vie selon l'unité. Elle est utilisée dans le cadre du pattern Strategy
 */
class HPLoss
{
	public:
		/**
		 * @brief destructeur (évite les warning)
		 */
		//virtual ~HPLoss();
		
		/**
		 * @brief Méthode virtuelle pure de perte d'hp des unité
		 * @param value un entier positif
		 * @param u l'unité qui prend des dégats
		 */
		virtual void hpLoss(unsigned int value, Unit* u) = 0;
		
		/**
		 * @brief Méthode virtuelle pure de perte d'hp des bases
		 * @param value un entier positif
		 * @param b la base qui prend des dégats
		 */
		virtual void hpLoss(unsigned int value, Base* b) = 0;
};


#endif // HPLOSS_HPP

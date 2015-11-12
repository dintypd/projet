/**
 * @file attackable.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/11/2015
 * @brief Définition de la classe Attackable
**/

#ifndef ATTACKABLE_H
#define ATTACKABLE_H

class HPLoss;

class Attackable
{
	protected:
		HPLoss* _hpLoss;
		unsigned int _hp;
					 _maxHP;
		
	public:
		/**
		 * @brief Constructeur
		 * @param hpLoss un comportement de perte d'hp
		 */
		Attackable(HPLoss* hpLoss);
		
		/**
		 * @brief Appel au comportement de perte d'hp
		 * @param value le nombre d'hp à perdre
		 */
		void hpLoss(unsigned int value);
		
		/**
		 * @brief Test de l'appartenance à la sous-classe Tower
		 * @return vrai si cette classe est une tour
		 */
		virtual bool isTower() const = 0;
		
		/**
		 * @brief Test de l'appartenance à la sous-classe Unit
		 * @return vrai si cette classe est une unité
		 */
		virtual bool isUnit() const = 0;
		
		/**
		 * @brief Test de l'appartenance à la sous-classe Base
		 * @return vrai si cette classe est une base
		 */
		virtual bool isBase() const = 0;
};

#endif // ATTACKABLE_H

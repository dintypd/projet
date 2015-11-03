/**
 * @file base.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Base
**/

#ifndef BASE_H
#define BASE_H

/**
 * @class Base base.h
 * 
 * @brief Classe définissant une base
 */
class Base
{
	private:
		unsigned int _hp,
					 _summonRange,
					 _buildRange;
		
	public:
		/**
		 * @brief Constructeur
		 */
		Base(unsigned int hp, unsigned int summonRange, unsigned int buildRange);
		
		/**
		 * @brief Accesseur du nombre de points de vie
		 * @return Le nombre de points de vie de la base
		 */
		unsigned int getHp() const;
		
		/**
		 * @brief Accesseur de la portée d'invocation
		 * @return La portée d'invocation de la base
		 */
		unsigned int getSummonRange() const;
		
		/**
		 * @brief Accesseur de la portée de construction
		 * @return La portée de construction de la base
		 */
		unsigned int getBuildRange() const;
};
 
#endif // BASE_H




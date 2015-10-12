/**
 * @file base.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Base
**/

#ifndef BASE_H
#define BASE_H

//#include "unit.h"
#include "position.h"

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
		Base();
		
		unsigned int getHp() const;
		
		unsigned int getSummonRange() const;
		
		unsigned int getBuildRange() const;
};
 
#endif // BASE_H




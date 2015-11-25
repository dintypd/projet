/**
 * @file base.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Base
**/

#ifndef BASE_HPP
#define BASE_HPP

#include "position.hpp"

class Player;
class HPLoss;

/**
 * @class Base base.hpp
 * 
 * @brief Classe définissant une base
 */
class Base
{
	private:
		unsigned int _hp,
					 _maxHP,
					 _summonRange,
					 _buildRange;
		Player* _player;
		HPLoss* _hpLoss;
		Position _position;
		
	public:
		/**
		 * @brief Constructeur
		 */
		Base(unsigned int hp, unsigned int summonRange, unsigned int buildRange, HPLoss* hpLoss, Position position);
		
		/**
		 * @brief Destructeur
		 */
		 ~Base();
		 
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
		
		/**
		 * @brief Affiche la base
		 */
		void afficher() const;
		
		/**
		 * @brief Modificateur du nombre de points de vie
		 * @param value la nouvelle valeur
		 */
		void setHP(unsigned int value);
		
		/**
		 * @brief Accesseur des points de vie
		 * @return le nombre de pdv
		 */
		unsigned int getHP() const;
		
		/**
		 * @brief Accesseur des points de vie max
		 * @return le nombre de pdv max
		 */
		unsigned int getMaxHP() const;
		
		/**
		 * @brief Modificateur du joueur associé à la base
		 * @param player le joueur
		 */
		void setPlayer(Player* player);
		
		/**
		 * @brief Accesseur de la position de la base
		 * @return la position
		 */
		Position getPosition() const;
		
		/**
		 * @brief Modificateur de la position de la base
		 * @param position la nouvelle position
		 */
		void setPosition(Position position);
		
		/**
		 * @brief L'unité perd des points de vie
		 * @param value Le nomdre d'HP perdus
		 */
		void hpLoss(unsigned int value);
};
 
#endif // BASE_HPP




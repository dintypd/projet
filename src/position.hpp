/**
 * @file position.hpp
 * @author A. Perhirin B. Le Clère
 * @date 5/10/2015
 * @brief definition de la classe Position
**/

#ifndef POSITION_HPP
#define POSITION_HPP


/**
 * @class Position position.hpp
 * 
 * @brief Classe implémentant une position sur la map
 *
 **/

class Position
{
	private:
		unsigned int _X; 	//position axe X
		unsigned int _Y; 	//position axe Y
		
	public:
		/**
		* @brief Constructeur, crée une position
		* @param X
		* @param Y
		**/
		Position(unsigned int X, unsigned int Y);

		/**
		* @brief getter de X 
		* @return X, la valeur de X
		**/
		unsigned int getX();

		/**
		* @brief getter de Y
		* @return Y, la valeur de Y
		**/
		unsigned int getY();

		/**
		* @brief setter de X 
		* @param x, la nouvelle valeur de X
		**/
		void setX(unsigned int x);

		/**
		* @brief setter de Y 
		* @param y, la nouvelle valeur de Y
		**/
		void setY(unsigned int y);

		/**
		* @brief renvoie la distance entre la position actuelle et une autre position
		* @param position, l'autre position 
		**/
		unsigned int distance(Position position) const;

		/**
		* @brief surcharge de l'opérateur ==
		*/
		bool operator==(Position const& position);

		/**
		 * @brief affiche la position
		 */
		void afficher() const;

		/**
		 * @brief méthode qui calcule la position au dessus de "this"
		 */
		Position up() const;

		/**
		 * @brief méthode qui calcule la position en dessous de "this"
		 */
		Position down() const;

		/**
		 * @brief méthode qui calcule la position a gauche de "this"
		 */
		Position left() const;

		/**
		 * @brief méthode qui calcule la position a droite de "this"
		 */
		Position right() const;
};
#endif // POSITION_HPP

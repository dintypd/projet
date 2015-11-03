/**
 * @file decor.h
 * @author B. Le Clère, A. Perhirin
 * @since 06/10/2015
 * @brief Définition de la classe Decor
**/

#ifndef DECOR_H
#define DECOR_H

#include "position.h"

/**
 * @class Decor decor.h
 * 
 * @brief Classe permettant l'utilisation de décors
 */
class Decor
{
	private:
		unsigned int _id; // identifiant unique
		static unsigned int _nextId; // le prochain objet aura cet identifiant + 1
		Position _position;
		bool _viewLine; // la ligne de vue
		
	public:
		/**
		 * @brief Constructeur
		 * @param position La position du décor sur la carte
		 */
		Decor(Position position, bool _viewLine);
		
		/**
		 * @brief Accesseur de l'identifiant
		 * @return l'identifiant du décor
		 */
		unsigned int getId() const;
		
		/**
		 * @brief Accesseur de la position
		 * @return la position du décor
		 */
		Position getPosition() const;
		
		/**
		 * @brief Permet de savoir si le décor autorise la ligne de vue
		 * @return vrai si le décor autorise la ligne de vue
		 */
		bool isViewLine() const;
};
 
#endif // DECOR_H



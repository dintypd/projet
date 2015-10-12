/**
 * @file position.h
 * @author A. Perhirin B. Le Clère
 * @date 5/10/2015
 * @brief definition de la classe Position
**/

#ifndef POSITION_H
#define POSITION_H


/**
 * @class Position 
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
		// méthodes
		
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
      unsigned int distance(Position position);
      
      /**
       * @brief surcharge de l'opérateur ==
       */
      bool operator==(Position const& position);
};
#endif

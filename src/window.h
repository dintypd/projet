/**
 * @file window.h
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe d'affichage
**/

#ifndef WINDOW_H
#define WINDOW_H

#include "observer.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Subject;
class Game;

/**
 * @class Window window.h
 *
 * @brief Affichage d'une fenêtre
 */
class Window : public Observer
{
	private:
		Game * _g;
		sf::RenderWindow _window;
		std::vector<std::vector<unsigned int>> _tiles;

	public:
		/**
		 * @brief Constructeur qui lance la fenêtre
		 */
		Window(Game* g);

		/**
		 * @brief Méthode d'update du pattern obervateur, met à jour la couleur du cercle
		 * @param s un sujet
		 */
		void update(Subject* s);

		/**
		 * @brief Méthode qui ferme la fenêtre
		 */
		void quit();
};

#endif // WINDOW_H


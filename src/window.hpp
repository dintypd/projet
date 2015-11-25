/**
 * @file window.hpp
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe d'affichage
**/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "observer.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Subject;
class Game;
class Map;

/**
 * @class Window window.hpp
 *
 * @brief Affichage d'une fenêtre
 */
class Window : public Observer
{
	private:
		Map * _m;
		sf::RenderWindow _window;
		std::vector<std::vector<unsigned int>> _tiles;

	public:
		/**
		 * @brief Constructeur qui lance la fenêtre
		 */
		Window(Map* m);

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

#endif // WINDOW_HPP


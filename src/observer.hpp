/**
 * @file observer.hpp
 * @author B. Le Clère A. Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe abstraite observateur
**/

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Subject;

/**
 * @class Observeur observeur.hpp
 *
 * @brief Classe abstraite définissant le comportement des toutes les classes observatrices
 */
class Observer
{
	public:
		/**
		 * @brief méthode appelée lors de la mise a jour du sujet
		 * @param s un sujet
		 */
		virtual void update(Subject* s) = 0;
};

#endif // OBSERVER_HPP

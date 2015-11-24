/**
 * @file observer.hpp
 * @author B. Le Clère A. Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe abstraite observateur
**/

#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

/**
 * @class Observeur observeur.h
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

#endif // OBSERVER_H

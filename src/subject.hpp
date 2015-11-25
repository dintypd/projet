/**
 * @file subject.hpp
 * @author B. Le Clère A. Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe abstraite sujet
**/

#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>

class Observer;
class Data;
class Map;

/**
 * @class Subject subject.hpp
 * 
 * @brief Classe abstraite définissant le comportement des toutes les classes sujets
 */
class Subject
{
	public:
		/**
		 * @brief ajout d'un observateur
		 */
		virtual void addObs(Observer* o) = 0;
		
		/**
		 * @brief suppresion d'un observateur
		 */
		virtual void rmObs(Observer* o) = 0;
		
		/**
		 * @brief notification de tous les observateurs
		 */
		virtual void notifyObs() = 0;
		
		/**
		 * @brief récupèration des données
		 */
		virtual Data* getData() = 0;
		
		/**
		 * @brief récupèration de la map
		 */
		virtual Map* getMap() = 0;
};

#endif // SUBJECT_HPP

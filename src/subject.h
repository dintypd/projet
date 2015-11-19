/**
 * @file subject.h
 * @author B. Le Clère A. Perhirin
 * @since 11/11/2015
 * @brief Définition de la classe abstraite sujet
**/

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Data;
class Map;

/**
 * @class Subject subject.h
 * 
 * @brief Classe abstraite définissant le comportement des toutes les classes sujets
 */
class Subject
{
	public:
		virtual void addObs(Observer* o) = 0;
		virtual void rmObs(Observer* o) = 0;
		virtual void notifyObs() = 0;
		virtual Data* getData() = 0;
		virtual Map* getMap() = 0;
};

#endif // SUBJECT_H

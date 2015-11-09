/**
 * @file spawner.h
 * @author B. Le Clère, A. Perhirin
 * @since 06/11/2015
 * @brief Définition de la classe Spawner
**/

#ifndef SPAWNER_H
#define SPAWNER_H

class Unit;
class Position;

/**
 * @class Spawner spawner.h
 * 
 * @brief Classe permettant l'utilisation des spawner (générateur d'unités)
 */
class Spawner
{
	private:
		Unit* _prototype;

	public:
		/**
		 * Constructeur
		 * @param prototype le prototype qui sert de base au spawner
		 */
		Spawner(Unit* prototype);
		
		/**
		 * Méthode qui copie le prototype et retourne l'unité correspondante
		 * @param position la position que prendra l'unité retournée
		 * @return une unité correspondante au prototype
		 */
		Unit* spawnUnit(Position position);
		
		/**
		 * Retourne le coût de l'unité
		 * @return un entier correspondant au cout
		 */
		unsigned int getCost();
};

#endif // SPAWNER_H

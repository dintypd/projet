/**
 * @file spawner.h
 * @author B. Le Clère, A. Perhirin
 * @since 06/11/2015
 * @brief Définition de la classe Spawner
**/

#ifndef SPAWNER_H
#define SPAWNER_H

class Unit;

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
		Spawner(Unit* prototype);
		Unit* spawnUnit();
};

#endif // SPAWNER_H

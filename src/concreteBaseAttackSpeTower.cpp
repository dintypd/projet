/**
 * @file attack.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation del'attaque de base pour les unités spécialisées dans l'attaque de tours
 *
**/

#include "concreteBaseAttackSpeTower.h"
#include "map.h"
#include <iostream>

using namespace std;

void ConcreteBaseAttackSpeTower::attack(Position position, Map* map)
{
	if(map->isUnitAt(position))
	{
		//Unit *u = map->getUnitAt(position);
		cout << "unité trouvée" << endl;
	}
	else
	{
		cout << "pas d'attaque" << endl;
	}
}


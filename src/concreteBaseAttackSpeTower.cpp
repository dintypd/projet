/**
 * @file attack.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation del'attaque de base pour les unités spécialisées dans l'attaque de tours
 *
**/

#include "concreteBaseAttackSpeTower.h"
#include "map.h"
#include "unit.h"
#include "position.h"
#include <iostream>

using namespace std;

void ConcreteBaseAttackSpeTower::attack(Position position, Map* map, unsigned int dmgs)
{
	if(map->isUnitAt(position))
	{
		Unit *u = map->getUnitAt(position);
		u->hpLoss(dmgs);
		cout << "unité trouvée" << endl;
	}
	else
	{
		cout << "pas d'attaque" << endl;
	}
}


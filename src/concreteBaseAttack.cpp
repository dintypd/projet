/**
 * @file concreteBaseAttack.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de l'attaque de base
 *
**/

#include "concreteBaseAttack.h"
#include "map.h"
#include "unit.h"
#include <iostream>

using namespace std;

void ConcreteBaseAttack::attack(Position position, Map* map, unsigned int dmgs)
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

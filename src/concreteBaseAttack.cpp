/**
 * @file attack.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation des méthodes des stratégies d'attaque
 *
**/

#include "concreteBaseAttack.h"
#include <iostream>

using namespace std;

void ConcreteBaseAttack::attack(Position position, Map* map)
{
	if(map->isUnitAt(position))
	{
		Unit *u = map->getUnitAt(position);
		cout << "unité trouvée" << endl;
	}
	else
	{
		cout << "pas d'attaque" << endl;
	}
}

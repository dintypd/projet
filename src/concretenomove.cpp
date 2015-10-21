/**
 * @file concretenomove.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation du non mouvement
 *
**/

#include "concretenomove.h"
#include "path.h"
#include "map.h"
#include "unit.h"
#include <iostream>

using namespace std;

void ConcreteNoMove::move(Path* path, Map* map, Unit* u)
{
	cout << "cette unité ne bouge pas!" << endl;
}

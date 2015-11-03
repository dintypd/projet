/**
 * @file concretemove.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation du mouvement
 *
**/

#include "concretemove.h"
#include "map.h"
#include "path.h"
#include "unit.h"
#include <iostream>

using namespace std;

void ConcreteMove::move(Path* path, Map* map, Unit* u)
{
	if(map->isValidPath(u, path))
	{
		u->setPosition(path->getPosition(path->size()-1));
	}
}


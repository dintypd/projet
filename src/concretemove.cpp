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
	if(path->size() <= u->getMP())
	{
		if(map->isValidPath(u, path))
		{
			u->afficher();
			u->setMP(u->getMP()-path->size());
			u->setPosition(path->getPosition(path->size()-1));
			cout << "---> perd : " << path->size() << " pm" << endl;
			cout << "---> pm : " << u->getMP() << "/" << u->getMaxMP() << endl;
			cout << "---> se déplace en : ";
			u->getPosition().afficher();
			cout << endl;
		}
		else
		{
			cout << "Le chemin de déplacement voulu est invalide." << endl;
		}
	}
	else
	{
		cout << "L'unité n'a pas assez de pm : " << u->getMP() << " pm" << endl;
	}
}


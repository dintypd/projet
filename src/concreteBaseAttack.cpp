/**
 * @file concreteBaseAttack.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de l'attaque de base
 *
**/

#include "concreteBaseAttack.h"
#include <iostream>
#include "map.h"
#include "position.h"
#include "unit.h"
#include "base.h"

using namespace std;

ConcreteBaseAttack::ConcreteBaseAttack(unsigned int ap) : Attack(ap)
{}

void ConcreteBaseAttack::attack(Position position, Map* map, Unit* attacker)
{
	// on cherche l'unité
	Unit* u = map->getUnitAt(position);
	Base* b = map->getBaseAt(position);
	
	if(u != 0 || b != 0)
	{
		if(attacker->getAP() >= _ap)
		{
			// récupération des données
			
			unsigned int dmgs = attacker->getDmgs();

			// perte d'hp de  l'attaqué
			if(u != 0)
				u->hpLoss(dmgs);
			else if(b != 0)
				b->hpLoss(dmgs);

			// perte d'ap de  l'attaquant
			attacker->setAP(attacker->getAP()-_ap);

			// affichage
			attacker->afficher();
			cout << "---> perd : " << _ap << " pa" << endl;
			cout << "---> pa : " << attacker->getAP() << "/" << attacker->getMaxAP() << endl;
			cout << "---> inflige : " << dmgs << " hp" <<endl;
		}
		else
		{
			cout << "L'unité n'a plus assez de pa : " << attacker->getAP() << " pa" << endl;
		}
	}
	else
	{
		// si on a pas trouvé d'unité à attaquer
		cout << "Rien à attaquer en ";
		position.afficher();
		cout << endl;
	}
}

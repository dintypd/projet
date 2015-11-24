/**
 * @file concretehploss.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de la perte d'HP de base
 *
**/

#include "concretehploss.h"
#include "unit.h"
#include "base.h"
#include <iostream>

using namespace std;

void ConcreteHPLoss::hpLoss(unsigned int value, Unit* u)
{
	// on retire les hp
	if(value < u->getHP())
	{
		u->setHP(u->getHP()-value);
	}
	else
	{
		u->setHP(0);
	}

	// on affiche les infos
	u->afficher();
	cout << "---> perd : " << value << " hp" << endl;
	cout << "---> hp : " << u->getHP() << "/" << u->getMaxHP() << endl;
	if(u->getHP() == 0)
	{
		cout << "---> l'unité est morte." << endl;
	}
}

void ConcreteHPLoss::hpLoss(unsigned int value, Base* b)
{
	// on retire les hp
	if(value < b->getHP())
	{
		b->setHP(b->getHP()-value);
	}
	else
	{
		b->setHP(0);
	}

	// on affiche les infos
	b->afficher();
	cout << "---> perd : " << value << " hp" << endl;
	cout << "---> hp : " << b->getHP() << "/" << b->getMaxHP() << endl;
	if(b->getHP() == 0)
	{
		cout << "---> la base est détruite." << endl;
	}
}

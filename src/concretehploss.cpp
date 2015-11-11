/**
 * @file concretehploss.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de la perte d'HP de base
 *
**/

#include "concretehploss.h"
#include "unit.h"
#include <iostream>

using namespace std;

void ConcreteHPLoss::hpLoss(unsigned int value, Unit* u)
{
	// on retire les hp
	u->setHP(u->getHP()-value);

	// on affiche les infos
	u->afficher();
	cout << "---> perd : " << value << " hp" << endl;
	cout << "---> hp : " << u->getHP() << "/" << u->getMaxHP() << endl;
}

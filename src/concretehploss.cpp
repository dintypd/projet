/**
 * @file concretehploss.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de la perte d'HP de base
 *
**/

#include "concretehploss.h"
#include "attackable.h"
#include <iostream>

using namespace std;

void ConcreteHPLoss::hpLoss(unsigned int value, Attackable* attacked)
{
	// on retire les hp
	attacked->setHP(attacked->getHP()-value);

	// on affiche les infos
	attacked->afficher();
	cout << "---> perd : " << value << " hp" << endl;
	cout << "---> hp : " << attacked->getHP() << "/" << attacked->getMaxHP() << endl;
}

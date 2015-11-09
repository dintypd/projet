/**
 * @file archer.cpp
 * @author A. Perhirin B. Le Clère
 * @since 09/11/2015
 * @brief implémentation des méthodes de la classe archer
 *
**/

#include "archer.h"
#include <iostream>

using namespace std;

Archer::Archer( unsigned int range, 
				unsigned int ap, 
				unsigned int mp, 
				unsigned int hp,
				unsigned int dmgs, 
				unsigned int cost,
				Attack* attack,
				HPLoss* hpLoss,
				Move* move,
				Position position) : Unit(range, ap, mp, hp, dmgs, cost, attack, hpLoss, move, position)
{
	// rien à faire
}

Unit* Archer::clone(Position position)
{
	return new Archer(_range, _ap, _mp, _hp, _dmgs, _cost, _attack, _hpLoss, _move, position);
}

string Archer::classe()
{
	return "archer";
}

void Archer::afficherInfos()
{
	cout << "Classe : archer" << endl;
	cout << "Position : " << _position.afficher();
	cout << "PA : " << _ap << endl;
	cout << "PM : " << _mp << endl;
	cout << "HP : " << _hp << endl;
}
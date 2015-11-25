/**
 * @file archer.cpp
 * @author A. Perhirin B. Le Clère
 * @since 09/11/2015
 * @brief implémentation des méthodes de la classe archer
 *
**/

#include "archer.hpp"

#include <iostream>

using namespace std;

Archer::Archer(unsigned int range, 
			   unsigned int ap, 
			   unsigned int mp, 
			   unsigned int hp,
			   unsigned int dmgs, 
			   unsigned int cost,
			   Attack* attack,
			   HPLoss* hpLoss,
			   Move* move,
			   Position position,
			   string image) 
: Unit(range, ap, mp, hp, dmgs, cost, attack, hpLoss, move, position, "archer.png")
{}

Unit* Archer::clone(Position position) const
{
	return new Archer(_range, _ap, _mp, _hp, _dmgs, _cost, _attack, _hpLoss, _move, position, _image);
}

string Archer::classe() const
{
	return "archer";
}

void Archer::afficherInfos() const
{
	cout << "Classe : archer" << endl;
	cout << "Position : ";
	_position.afficher();
	cout << endl;
	cout << "PA : " << _ap << "/" << _apMax << endl;
	cout << "PM : " << _mp << "/" << _mpMax << endl;
	cout << "HP : " << _hp << "/" << _hpMax << endl;
	cout << "Dommages : " << _dmgs << endl;
	cout << "Portée : " << _range << endl;
}

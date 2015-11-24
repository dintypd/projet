/**
 * @file knight.cpp
 * @author A. Perhirin B. Le Clère
 * @since 06/10/2015
 * @brief implémentation des méthodes de la classe knight
 *
**/

#include "knight.h"

#include <iostream>

using namespace std;

Knight::Knight(unsigned int range, 
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
: Unit(range, ap, mp, hp, dmgs, cost, attack, hpLoss, move, position, "knight.png")
{}

Unit* Knight::clone(Position position) const
{
	return new Knight(_range, _ap, _mp, _hp, _dmgs, _cost, _attack, _hpLoss, _move, position, _image);
}

string Knight::classe() const
{
	return "knight";
}

void Knight::afficherInfos() const
{
	cout << "Classe : knight" << endl;
	cout << "Position : ";
	_position.afficher();
	cout << endl;
	cout << "PA : " << _ap << "/" << _apMax << endl;
	cout << "PM : " << _mp << "/" << _mpMax << endl;
	cout << "HP : " << _hp << "/" << _hpMax << endl;
	cout << "Dommages : " << _dmgs << endl;
	cout << "Portée : " << _range << endl;
}

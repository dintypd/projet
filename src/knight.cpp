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

Knight::Knight( unsigned int range, 
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

Unit* Knight::clone(Position position)
{
	return new Knight(_range, _ap, _mp, _hp, _dmgs, _cost, _attack, _hpLoss, _move, position);
}

string Knight::classe()
{
	return "knight";
}

void Knight::afficherInfos()
{
	cout << "Classe : knight" << endl;
	cout << "Position : " << _position.afficher();
	cout << "PA : " << _ap << endl;
	cout << "PM : " << _mp << endl;
	cout << "HP : " << _hp << endl;
}
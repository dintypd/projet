/**
 * @file knight.cpp
 * @author A. Perhirin B. Le Clère
 * @since 06/10/2015
 * @brief implémentation des méthodes de la classe knight
 *
**/

#include "knight.h"

using namespace std;

Knight::Knight( unsigned int range, 
				unsigned int ap, 
				unsigned int mp, 
				unsigned int hp,
				unsigned int dmgs, 
				unsigned int cost,
				Attack* attack,
				HPLoss* hpLoss,
				Move* move) : Unit(range, ap, mp, hp, dmgs, cost, attack, hpLoss, move)
{
	// rien à faire
}

Unit* Knight::clone()
{
	return new Knight(_range, _ap, _mp, _hp, _dmgs, _cost, _attack, _hpLoss, _move);
}

string Knight::classe()
{
	return "knight";
}

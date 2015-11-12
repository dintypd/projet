/**
 * @file unit.cpp
 * @author A. Perhirin B. Le Clère
 * @since 16/10/2015
 * @brief implémentation des méthodes de la classe Unit
 *
**/

#include <iostream>
#include "unit.h"
#include "attack.h"
#include "move.h"
#include "hploss.h"
#include "path.h"

using namespace std;

unsigned int Unit::_nextId = 0;

Unit::Unit( unsigned int range, 
			unsigned int ap, 
			unsigned int mp, 
			unsigned int hp,
			unsigned int dmgs, 
			unsigned int cost,
			Attack* attack,
			HPLoss* hpLoss,
			Move* move,
			Position position) : 	_id(++_nextId), 
							_range(range), 
							_ap(ap),
							_apMax(ap),
							_mp(mp),
							_mpMax(mp),
							_hp(hp),
							_hpMax(hp),
							_dmgs(dmgs), 
							_cost(cost), 
							_position(position), 
							_attack(attack),
							_move(move),
							_summoner(false), 
							_builder(false),
							Attackable(hpLoss)
{}

Position Unit::getPosition() const
{
	return _position;
}

unsigned int Unit::getId() const
{
	return _id;
}

unsigned int Unit::getRange() const
{
	return _range;
}

unsigned int Unit::getAP() const
{
	return _ap;
}

unsigned int Unit::getMaxAP() const
{
	return _apMax;
}

unsigned int Unit::getMP() const
{
	return _mp;
}

unsigned int Unit::getMaxMP() const
{
	return _mpMax;
}

unsigned int Unit::getHP() const
{
	return _hp;
}

unsigned int Unit::getMaxHP() const
{
	return _hpMax;
}

unsigned int Unit::getDmgs() const
{
	return _dmgs;
}

unsigned int Unit::getCost() const
{
	return _cost;
}

bool Unit::isSummoner() const
{
	return _summoner;
}

bool Unit::isBuilder() const
{
	return _builder;
}

void Unit::setRange( unsigned int range )
{
	_range = range;
}

void Unit::setAP( unsigned int ap ) 
{
	_ap = ap;
}

void Unit::setMP( unsigned int mp ) 
{
	_mp = mp;
}

void Unit::setHP( unsigned int hp )
{
	_hp = hp;
}

void Unit::setDmgs( unsigned int dmgs ) 
{
	_dmgs = dmgs;
}

void Unit::setPosition( Position pos )
{
	_position = pos;
}

void Unit::setSummoner()
{
	_summoner = true;
}

void Unit::setBuilder()
{
	_builder = true;
}

void Unit::attack( Position pos, Map *map )
{
	_attack->attack(pos, map, this);
}

void Unit::hpLoss( unsigned int value )
{
	_hpLoss->hpLoss(value, this);
}

void Unit::move( Path *path, Map *map )
{
	_move->move(path, map, this);
}

void Unit::afficher()
{
	cout << "ID: " << _id << " ; Classe: " << classe() << " ; Position: ";
	_position.afficher();
	cout << endl;
}

void Unit::endTurn()
{
	_ap = _apMax;
	_mp = _mpMax;
}

bool Unit::isTower() const
{
	return false;
}

bool Unit::isUnit() const
{
	return true;
}

bool Unit::isBase() const
{
	return false;
}

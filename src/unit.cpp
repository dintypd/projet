/**
 * @file unit.cpp
 * @author A. Perhirin B. Le Clère
 * @since 16/10/2015
 * @brief implémentation des méthodes de la classe Unit
 *
**/

#include "unit.h"

using namespace std;

Unit::Unit( unsigned int range, 
			unsigned int ap, 
			unsigned int mp, 
			unsigned int hp,
			unsigned int dmgs, 
			unsigned int cost, 
			Position position) : 	_id(++_nextId), 
									_range(range), 
									_ap(ap), 
									_mp(mp), 
									_hp(hp), 
									_dmgs(dmgs), 
									_cost(cost), 
									_position(position), 
									_summoner(false), 
									_builder(false),
									_attack = new ConcreteBaseAttack;
									_move = new ConcreteMove;
									_hpLoss = new ConcreteHPLoss;
{
		//rien a faire
}

Position Unit::getPosition() const
{
	return _position;
}

unsigned int Unit::_nextId = 0;

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

unsigned int Unit::getMP() const
{
	return _mp;
}

unsigned int Unit::getHP() const
{
	return _hp;
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

void Unit::setPos( Position pos )
{
	_pos = pos;
}

void Unit::setSummoner()
{
	_summoner = true;
}

void Unit::setBuilder()
{
	_builder = true;
}

void attack( Position pos, Map *map )
{
	_attack->attack(pos, *map);
}

void hpLoss( unsigned int value)
{
	_hpLoss->hpLoss(value);
}

void move( Path *path, Map *map )
{
	_move->move(*path, *map);
}


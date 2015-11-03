/**
 * @file unit.cpp
 * @author A. Perhirin B. Le Clère
 * @since 16/10/2015
 * @brief implémentation des méthodes de la classe Unit
 *
**/

#include "unit.h"
#include "attack.h"
#include "concreteBaseAttack.h"
#include "concreteBaseAttackSpeTower.h"
#include "concretehploss.h"
#include "concretehplossspedef.h"
#include "concretemove.h"
#include "concreteNoBaseAttack.h"
#include "concretenomove.h"
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
			Position position) : 	_id(++_nextId), 
									_range(range), 
									_ap(ap), 
									_mp(mp), 
									_hp(hp), 
									_dmgs(dmgs), 
									_cost(cost), 
									_position(position), 
									_summoner(false), 
									_builder(false)
{
	_attack = new ConcreteBaseAttack();
	_move = new ConcreteMove();
	_hpLoss = new ConcreteHPLoss();
}

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
	_attack->attack(pos, map, _dmgs);
}

void Unit::hpLoss( unsigned int value )
{
	_hpLoss->hpLoss(value, this);
}

void Unit::move( Path *path, Map *map )
{
	_move->move(path, map, this);
}


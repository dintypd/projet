/**
 * @file player.cpp
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Implémentation de la classe Player
**/

#include "position.hpp"
#include "player.hpp"
#include "unit.hpp"

#include <iostream>

using namespace std;

unsigned int Player::_nextId = 0;

Player::Player(string name, unsigned int golds, Base* base) 
: _name(name)
, _id(++_nextId)
, _base(base)
, _golds(golds)
{} 

Player::~Player()
{
	for(auto unit : _units)
	{
		delete(unit.second);
	}
}

unsigned int Player::getId() const
{
	return _id;
}

string Player::getName() const
{
	return _name;
}

unsigned int Player::getGolds() const
{
	return _golds;
}

map<unsigned int, Unit*> * Player::getUnits()
{
	return &_units;
}

Base* Player::getBase() const
{
	return _base;
}

void Player::summon(Unit* unit/*, Position position*/)
{
	_units[unit->getId()] = unit;
	rmGolds(unit->getCost());
}

void Player::kill(Unit* unit)
{
	if(_units.count(unit->getId()))
		_units.erase(unit->getId());
}

void Player::addGolds(unsigned int golds)
{
	_golds += golds;
}

void Player::rmGolds(unsigned int golds)
{
	_golds -= golds;
}

void Player::afficheGolds()
{
	cout << _golds << "g" << endl;
}

void Player::setNext(Player* next)
{
	_next = next;
}

Player* Player::getNext() const
{
	return _next;
}

Unit* Player::getUnit(unsigned int id) const
{
	if(_units.count(id))
	{
		return _units.at(id);
	}

	return 0;
}

void Player::afficheUnits()
{
	if(_units.size() > 0)
	{
		for(auto unit : _units)
		{
			unit.second->afficher();
		}
	}
	else
	{
		cout << "Aucune unité." << endl;
	}
}

void Player::endTurn()
{
	for(auto unit : _units)
	{
		unit.second->endTurn();
	}

	_golds += 120;
}

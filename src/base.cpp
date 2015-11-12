/**
 * @file base.cpp
 * @author A. Perhirin B. Le Clère
 * @since 14/10/2015
 * @brief implémentation des méthodes de la classe Base
 *
**/

#include "base.h"
#include "player.h"
#include "hploss.h"
#include "position.h"
#include <iostream>

using namespace std;

Base::Base(unsigned int hp, unsigned int summonRange, unsigned int buildRange, HPLoss* hpLoss, Position position) 
: _hp(hp)
, _maxHP(hp)
, _summonRange(summonRange)
, _buildRange(buildRange)
, _player(0)
, _hpLoss(hpLoss)
, _position(position)
{}

void Base::afficher() const
{
	cout << "Base de " << _player->getName() << endl;
}

unsigned int Base::getSummonRange() const
{
	return _summonRange;
}

unsigned int Base::getBuildRange() const
{
	return _buildRange;
}

unsigned int Base::getHP() const
{
	return _hp;
}

unsigned int Base::getMaxHP() const
{
	return _maxHP;
}

void Base::setHP(unsigned int value)
{
	_hp = value;
}

void Base::setPlayer(Player* player)
{
	_player = player;
}

Position Base::getPosition() const
{
	return _position;
}

void Base::setPosition(Position position)
{
	_position = position;
}

void Base::hpLoss(unsigned int value)
{
	_hpLoss->hpLoss(value, this);
}

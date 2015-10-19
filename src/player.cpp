/**
 * @file player.cpp
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Implémentation de la classe Player
**/

#include "player.h"

using namespace std;

unsigned int Player::_nextId = 0;

Player::Player() : _id(++_nextId)
{
	// rien à faire
} 

unsigned int Player::getGolds() const
{
	return _golds;
}

vector<Unit*> Player::getUnits() const
{
	return _units;
}

Base Player::getBase() const
{
	return _base;
}

void Player::summon(Unit unit, Position position)
{
	// à implémenter
}

void Player::addGolds(unsigned int golds)
{
	_golds += golds;
}

void Player::rmGolds(unsigned int golds)
{
	_golds -= golds;
}

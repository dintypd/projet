/**
 * @file unit.cpp
 * @author A. Perhirin B. Le Clère
 * @since 16/10/2015
 * @brief implémentation des méthodes de la classe Unit
 *
**/

#include "unit.h"

using namespace std;

Unit::Unit(unsigned int range, Position position) : _range(range), _pos(position)
{
}

Position Unit::getPosition() const
{
	return _pos;
}


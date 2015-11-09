/**
 * @file position.cpp
 * @author A. Perhirin B. Le Clère
 * @since 06/10/2015
 * @brief implémentation des méthodes de la classe position
 *
**/
#include <stdlib.h>
#include <stdio.h>
#include "position.h"

using namespace std;

Position::Position(unsigned int X, unsigned int Y) : _X(X), _Y(Y) 
{
	// rien a faire
}

unsigned int Position::getX()
{
	return _X;
}

unsigned int Position::getY()
{
	return _Y;
}	
	
void Position::setX(unsigned int x)
{
	_X = x;
}

void Position::setY(unsigned int y)
{
	_Y = y;
}

unsigned int Position::distance(Position position) const
{
	return ( abs(_X - position.getX()) + abs(_Y - position.getY()) );
}

bool Position::operator==(Position const& position)
{
	return this->_X == position._X && this->_Y == position._Y;
}

void Position::afficher() const
{
	printf("[%d;%d]", _X, _Y);
}

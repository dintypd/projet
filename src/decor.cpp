/**
 * @file decor.h
 * @author B. Le Clère, A. Perhirin
 * @since 06/10/2015
 * @brief Implémentation de la classe Decor
**/

#include "decor.h"

unsigned int Decor::_nextId = 0;

Decor::Decor(Position position, bool viewLine) : _id(++_nextId), _position(position), _viewLine(viewLine)
{
	// rien à faire
} 

unsigned int Decor::getId() const
{
	return _id;
}

Position Decor::getPosition() const
{
	return _position;
}

bool Decor::isViewLine() const
{
	return _viewLine;
}

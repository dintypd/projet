/**
 * @file decor.h
 * @author B. Le Clère, A. Perhirin
 * @since 06/10/2015
 * @brief Implémentation de la classe Decor
**/

#include "decor.h"

unsigned int Decor::nextId = 0;

Decor::Decor(Position position) : _id(nextId++), _position(position), _viewLine(true)
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

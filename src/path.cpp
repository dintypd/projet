/**
 * @file path.cpp
 * @author A. Perhirin B. Le Clère
 * @since 06/10/2015
 * @brief implémentation des méthodes de la classe path
 *
**/

#include "path.h"

using namespace std;

Path::Path()
{
	//rien a faire
}
	
void Path::pushPos(Position pos)
{
	_path.push_back(pos);
}

Position Path::popPos()
{
	Position pos = _path.back();
	_path.pop_back();
	return pos;
}

unsigned int Path::size() const
{
	return _path.size();
}

Position Path::getPosition(unsigned int i) const
{
	return _path[i];
}

Position Path::operator[](unsigned int const & i)
{
	return _path[i];
}

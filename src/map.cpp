/**
 * @file map.cpp
 * @author B. Le Clère, A. Perhirin
 * @since 06/10/2015
 * @brief Implémentation de la classe Map
**/

#include "map.h"
#include "player.h"
#include "path.h"
#include "unit.h"
#include "decor.h"

using namespace std;

Map::Map()
{
	vector<bool> l1 {true, true, true, true, true};
	vector<bool> l2 {true, true, true, true, true};
	vector<bool> l3 {true, true, true, true, true};
	vector<bool> l4 {true, true, true, true, true};
	vector<bool> l5 {true, true, true, true, true};
	_tiles = {l1, l2, l3, l4, l5};
} 

bool Map::isValidPath(Unit* unit, Path path) const
{
	bool valid = true;
	unsigned int i = 1;
	
	if((unit->getPosition().distance(path[0]) != 1) || 
	   (isDecorAt(path[0])) || 
	   (isUnitAt(path[0])))
	{
		valid = false;
	}
	
	while(valid && i < path.size())
	{
		if((path[i-1].distance(path[i]) != 1) || 
		   (isDecorAt(path[i])) || 
		   (isUnitAt(path[i])) || 
		   !_tiles[path[i].getY()][path[i].getX()])
		{
			valid = false;
		}
		++i;
	}
	
	return valid;
}

bool Map::isValidViewLine(Unit* unit, Position position) const
{
	return true;
}

Unit* Map::getUnitAt(Position position) const
{
	unsigned int i = 0;
	unsigned int nbPlayers = _players.size();
	bool trouve = false;
	
	unsigned int j = 0, taille;
	
	while(!trouve && i < nbPlayers)
	{
		j = 0;
		taille = _players[i]->getUnits().size();
		
		while(!trouve && j < taille)
		{
			if(_players[i]->getUnits()[j]->getPosition() == position)
			{
				trouve = true;
			}
			++j;
		}
		++i;
	}
	
	return _players[i]->getUnits()[j];
}

bool Map::isUnitAt(Position position) const
{
	unsigned int i = 0;
	unsigned int nbPlayers = _players.size();
	bool trouve = false;
	
	unsigned int j = 0, taille;
	
	while(!trouve && i < nbPlayers)
	{
		j = 0;
		taille = _players[i]->getUnits().size();
		
		while(!trouve && j < taille)
		{
			if(_players[i]->getUnits()[j]->getPosition() == position)
			{
				trouve = true;
			}
			++j;
		}
		++i;
	}
	
	return trouve;
}

Decor* Map::getDecorAt(Position position) const
{
	unsigned int i = 0;
	unsigned int taille = _decors.size();
	bool trouve = false;
	
	while(i < taille && !trouve)
	{
		if(_decors[i]->getPosition() == position)
		{
			trouve = true;
		}
		++i;
	}
	
	return _decors[i];
}

bool Map::isDecorAt(Position position) const
{
	unsigned int i = 0;
	unsigned int taille = _decors.size();
	bool trouve = false;
	
	while(i < taille && !trouve)
	{
		if(_decors[i]->getPosition() == position)
		{
			trouve = true;
		}
		++i;
	}
	
	return trouve;
}

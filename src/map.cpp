/**
 * @file map.cpp
 * @author B. Le Clère, A. Perhirin
 * @since 06/10/2015
 * @brief Implémentation de la classe Map
**/

#include "map.h"
#include "player.h"
#include "decor.h"
#include "unit.h"
#include "path.h"

using namespace std;

Map::Map(std::vector<std::vector<bool>> tiles, 
			std::vector<Decor*> decors, 
			std::vector<Position> startingPositions) : _decors(decors), _tiles(tiles), _startingPositions(startingPositions)
{
	// calcul de la taille : on suppoe la map carrée
	_size = _tiles.size();
} 

bool Map::isValidPath(Unit* unit, Path* path) const
{
	bool valid = true;
	unsigned int i = 1;
	
	if((unit->getPosition().distance(path->getPosition(0)) != 1) || 
	   (isDecorAt(path->getPosition(0))) || 
	   (isUnitAt(path->getPosition(0))))
	{
		valid = false;
	}
	
	while(valid && i < path->size())
	{
		if((path->getPosition(i-1).distance(path->getPosition(i)) != 1) || 
		   (isDecorAt(path->getPosition(i))) || 
		   (isUnitAt(path->getPosition(i))) || 
		   !_tiles[path->getPosition(i).getY()][path->getPosition(i).getX()])
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
	map<unsigned int, Unit*> & currentUnits = _players.at(1)->getUnits();
	
	// on itère dans la liste des joueurs
	for(auto player : _players)
	{
		currentUnits = player.second->getUnits();
		// on itère dans la liste des unités
		for(auto unit : currentUnits)
		{
			if(unit.second->getPosition() == position)
			{
				return unit.second;
			}
		}
	}
	
	return 0;
}

bool Map::isUnitAt(Position position) const
{
	map<unsigned int, Unit*> & currentUnits = _players.at(1)->getUnits();
	
	// on itère dans la liste des joueurs
	for(auto player : _players)
	{
		currentUnits = player.second->getUnits();
		// on itère dans la liste des unités
		for(auto unit : currentUnits)
		{
			if(unit.second->getPosition() == position)
			{
				return true;
			}
		}
	}
	
	return false;
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

void Map::addPlayer(Player* player)
{
	_players[player->getId()] = player;
}

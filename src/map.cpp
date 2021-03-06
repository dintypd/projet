/**
 * @file map.cpp
 * @author B. Le Clère, A. Perhirin
 * @since 06/10/2015
 * @brief Implémentation de la classe Map
**/

#include "map.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "path.hpp"
#include "base.hpp"

#include <iostream>

using namespace std;

Map::Map(std::vector<std::vector<unsigned int>> tiles, 
			std::vector<Position> startingPositions) : _tiles(tiles), _startingPositions(startingPositions)
{
	// calcul de la taille : on suppose la map carrée
	_size = _tiles.size();
} 

Map::~Map()
{
	for(auto player : _players)
	{
		delete(player.second);
	}
}

bool Map::isValidPath(Unit* unit, Path* path) const
{
	bool valid = true;
	unsigned int i = 1;
	
	if((unit->getPosition().distance(path->getPosition(0)) != 1) || 
	   (isUnitAt(path->getPosition(0))) ||
	   (isBaseAt(path->getPosition(0))) ||
	   (isBlocked(path->getPosition(0))))
	{
		valid = false;
	}
	
	while(valid && i < path->size())
	{
		if((path->getPosition(i-1).distance(path->getPosition(i)) != 1) || 
		   (isUnitAt(path->getPosition(i))) || 
		   (isBaseAt(path->getPosition(0))) ||
		   (isBlocked(path->getPosition(i))))
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

bool Map::isValidSummonPosition(Position position, Player* player) const
{
	return position.getX() <= _size-1 &&
		   position.getY() <= _size-1 && 
		   !isUnitAt(position) &&
		   !isBlocked(position) && 
		   !isBaseAt(position) && 
		   position.distance(player->getBase()->getPosition()) <= player->getBase()->getSummonRange();
}


vector<vector<unsigned int>> Map::getTiles() const
{
	return _tiles;
}

Unit* Map::getUnitAt(Position position) const
{
	map<unsigned int, Unit*>* currentUnits = _players.at(1)->getUnits();
	
	// on itère dans la liste des joueurs
	for(auto player : _players)
	{
		currentUnits = player.second->getUnits();
		// on itère dans la liste des unités
		for(map<unsigned int, Unit*>::iterator unit = currentUnits->begin(); unit != currentUnits->end(); ++unit)
		{	
			if(unit->second->getPosition() == position)
			{
				return unit->second;
			}
		}
	}
	
	return 0;
}

bool Map::isUnitAt(Position position) const
{
	map<unsigned int, Unit*>* currentUnits = _players.at(1)->getUnits();
	
	// on itère dans la liste des joueurs
	for(auto player : _players)
	{
		// BUG A CE NIVEAU
		currentUnits = player.second->getUnits();
		// on itère dans la liste des unités
		for(map<unsigned int, Unit*>::iterator unit = currentUnits->begin(); unit != currentUnits->end(); ++unit)
		{	
			if(unit->second->getPosition() == position)
			{
				return true;
			}
		}
	}
	
	return false;
}

void Map::addPlayer(Player* player)
{
	_players[player->getId()] = player;
}

map<unsigned int, Player*> * Map::getPlayers()
{
	return &_players;
}

Unit* Map::getUnit(unsigned int id) const
{
	for(auto player : _players)
	{
		if(player.second->getUnit(id) != 0)
		{
			return player.second->getUnit(id);
		}
	}

	return 0;
}

bool Map::isUnit(unsigned int id) const
{
	for(auto player : _players)
	{
		if(player.second->getUnit(id) != 0)
		{
			return true;
		}
	}
	
	return false;
}

bool Map::isBaseAt(Position position) const
{
	for(auto start : _startingPositions)
	{
		if(start == position)
		{
			return true;
		}
	}
	
	return false;
}

Base* Map::getBaseAt(Position position) const
{
	for(auto player : _players)
	{
		Base* b = player.second->getBase();
		if(b->getPosition() == position)
		{
			return b;
		}
	}
	
	return 0;
}

unsigned int Map::getSize() const
{
	return _size;
}

bool Map::isBlocked(Position position) const
{
	return _tiles[position.getX()][position.getY()] == 0;
}

void Map::die(Unit* unit)
{
	for(auto player : _players)
	{
		player.second->kill(unit);
	}
}

void Map::baseBreak()
{
	for(auto player : _players)
	{
		if(player.second->getBase()->getHP() == 0)
		{
			cout << "La base de " << player.second->getName() << " est détruite, il a perdu." << endl;
			delete(player.second);
			_players.erase(player.first);
		}
	}
}

Player* Map::getWinner()
{
	for(auto player : _players)
	{
		return player.second;
	}
	return 0;
}

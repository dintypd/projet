/**
 * @file data.cpp
 * @author A. Perhirin B. Le Clère
 * @since 03/11/2015
 * @brief implémentation des méthodes de la classe Data
 *
**/

#include "data.h"
#include "position.h"
#include "attack.h"
#include "concreteBaseAttack.h"
#include "concreteBaseAttackSpeBase.h"
#include "concretehploss.h"
#include "concretehplossspedef.h"
#include "concretemove.h"
#include "move.h"
#include "hploss.h"
#include "knight.h"
#include "archer.h"
#include "spawner.h"

using namespace std;

Data::Data()
{
	_baseAttack = new ConcreteBaseAttack(3);
	_baseAttackSpeBase = new ConcreteBaseAttackSpeBase(3);
	
	_hpLoss = new ConcreteHPLoss();
	_hpLossSpeDef = new ConcreteHPLossSpeDef();
	
	_move = new ConcreteMove();
	
	Position p(0, 0);
	Knight* knightPrototype = new Knight(1, 8, 4, 160, 90, 100, _baseAttackSpeBase, _hpLoss, _move, p, "knight.png");
	Spawner* knightSpawner = new Spawner(knightPrototype);
	_spawnerList["knight"] = knightSpawner;
	
	Archer* archerPrototype = new Archer(6, 9, 3, 70, 150, 130, _baseAttack, _hpLossSpeDef, _move, p, "archer.png");
	Spawner* archerSpawner = new Spawner(archerPrototype);
	_spawnerList["archer"] = archerSpawner;
}

Data::~Data()
{
	delete(_baseAttack);
	delete(_baseAttackSpeBase);
	delete(_hpLoss);
	delete(_hpLossSpeDef);
	delete(_move);
}

// Map Data
vector<vector<unsigned int>> Data::getTiles_Map()
{
	vector<unsigned int> l1  {0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0};
	vector<unsigned int> l2  {0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0};
	vector<unsigned int> l3  {0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0};
	vector<unsigned int> l4  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l5  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l6  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l7  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l8  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l9  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l10 {0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0};
	vector<unsigned int> l11 {0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0};
	vector<unsigned int> l12 {0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0};
	
	vector<vector<unsigned int>> tiles = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12};
	
	return tiles;
}

vector<Position> Data::getStartingPositions_Map()
{
	Position p1(0, 6);
	Position p2(11, 5);
	
	vector<Position> startingPositions = {p1, p2};
	
	return startingPositions;
}

// Base Data
map<string, unsigned int> Data::getUnsignedIntData_Base()
{
	map<string, unsigned int> base;
	base["hp"] = 1500;
	base["summonRange"] = 4;
	base["buildRange"] = 2;
	
	return base;
}

HPLoss* Data::getHPLossBehavior_Base()
{
	return _hpLoss;
}

// Player
unsigned int Data::getGolds_Player()
{
	return 260;
}

// Spawner
Spawner* Data::getSpawner(std::string classe)
{
	return _spawnerList[classe];
}

bool Data::isClasse(string classe)
{
	return _spawnerList.count(classe);
}

vector<string> Data::getClasses()
{
	vector<string> classes;
	for(auto classe : _spawnerList)
	{
		classes.push_back(classe.first);
	}
	
	return classes;
}

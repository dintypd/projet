/**
 * @file data.cpp
 * @author A. Perhirin B. Le Clère
 * @since 03/11/2015
 * @brief implémentation des méthodes de la classe Data
 *
**/
#include "data.h"
#include "decor.h"
#include "position.h"
#include "attack.h"
#include "concreteBaseAttack.h"
#include "concreteBaseAttackSpeTower.h"
#include "concretehploss.h"
#include "concretehplossspedef.h"
#include "concretemove.h"
#include "concreteNoBaseAttack.h"
#include "concretenomove.h"
#include "move.h"
#include "hploss.h"
#include "knight.h"
#include "archer.h"
#include "spawner.h"

using namespace std;

Data::Data()
{
	_baseAttack = new ConcreteBaseAttack(3);
	_baseAttackSpeTower = new ConcreteBaseAttackSpeTower(3);
	_noBaseAttack = new ConcreteNoBaseAttack(0);
	
	_hpLoss = new ConcreteHPLoss();
	_hpLossSpeDef = new ConcreteHPLossSpeDef();
	
	_move = new ConcreteMove();
	_noMove = new ConcreteNoMove();
	
	Position p(0, 0);
	Knight* knightPrototype = new Knight(1, 8, 4, 160, 90, 100, _baseAttack, _hpLoss, _move, p);
	Spawner* knightSpawner = new Spawner(knightPrototype);
	_spawnerList["knight"] = knightSpawner;
	
	Archer* archerPrototype = new Archer(6, 9, 3, 70, 150, 130, _baseAttack, _hpLoss, _move, p);
	Spawner* archerSpawner = new Spawner(archerPrototype);
	_spawnerList["archer"] = archerSpawner;
}

// Map Data
vector<vector<unsigned int>> Data::getTiles_Map()
{
	vector<unsigned int> l1  {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0};
	vector<unsigned int> l2  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
	vector<unsigned int> l3  {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	vector<unsigned int> l4  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l5  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l6  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l7  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l8  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l9  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<unsigned int> l10 {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	vector<unsigned int> l11 {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
	vector<unsigned int> l12 {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0};
	
	vector<vector<unsigned int>> tiles = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12};
	
	return tiles;
}

vector<Decor*> Data::getDecors_Map()
{
	Decor d1(Position(4, 5), true);
	Decor d2(Position(7, 10), false);
	
	vector<Decor*> decors = {&d1, &d2};
	
	return decors;
}

vector<Position> Data::getStartingPositions_Map()
{
	Position p1(0, 6);
	Position p2(11, 7);
	
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

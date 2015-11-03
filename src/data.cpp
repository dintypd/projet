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

using namespace std;

Data::Data()
{
	_baseAttack = new ConcreteBaseAttack();
	_baseAttackSpeTower = new ConcreteBaseAttackSpeTower();
	_noBaseAttack = new ConcreteNoBaseAttack();
	
	_hpLoss = new ConcreteHPLoss();
	_hpLossSpeDef = new ConcreteHPLossSpeDef();
	
	_move = new ConcreteMove();
	_noMove = new ConcreteNoMove();
}

// Map Data
vector<vector<bool>> Data::getTiles_Map()
{
	vector<bool> l1  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l2  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l3  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l4  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l5  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l6  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l7  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l8  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l9  {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l10 {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l11 {true, true, true, true, true, true, true, true, true, true, true, true};
	vector<bool> l12 {true, true, true, true, true, true, true, true, true, true, true, true};
	
	vector<vector<bool>> tiles = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12};
	
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

// Knight Data
map<string, unsigned int> Data::getUnsignedIntData_Knight()
{
	map<string, unsigned int> knight;
	knight["range"] = 1;
	knight["ap"] = 8;
	knight["mp"] = 4;
	knight["hp"] = 160;
	knight["dmgs"] = 90;
	knight["cost"] = 100;
	
	return knight;
}

map<string, bool> Data::getBoolData_Knight()
{
	map<string, bool> knight;
	knight["summoner"] = false;
	knight["builder"] = false;
	
	return knight;
}

Attack* Data::getAttackBehavior_Knight()
{
	return _baseAttack;
}

HPLoss* Data::getHPLossBehavior_Knight()
{
	return _hpLoss;
}

Move* Data::getMoveBehavior_Knight()
{
	return _move;
}

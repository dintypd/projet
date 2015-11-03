#include <iostream>
#include "map.h"
#include "path.h"
#include "unit.h"
#include "base.h"
#include "player.h"
#include "data.h"

using namespace std;

int main()
{
	Data data;
	Map* map = new Map(data.getTiles_Map(), data.getDecors_Map(), data.getStartingPositions_Map());
	/*Map* map = new Map();
	
	Position p0(3,0), p1(2,0), p2(1,0), p3(0,0);
	Path* path = new Path();
	path->pushPos(p1);
	path->pushPos(p2);
	path->pushPos(p3);
	
	Unit* unit = new Unit(10, 15, 20, 25, 30, 35, p0);
	
	Base* base1 = new Base(100, 10, 15);
	
	Player* player1 = new Player("Benjou", 100, base1);
	
	player1->summon(unit);
	
	map->addPlayer(player1);
	
	unit->getPosition().afficher();
	unit->move(path, map);
	unit->getPosition().afficher();*/
	return 0;
}

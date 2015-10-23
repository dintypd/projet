#include <iostream>
#include "map.h"
#include "path.h"
#include "unit.h"

using namespace std;

int main()
{
	Map* m = new Map();
	
	Position p0(3,0), p1(0,0), p2(0,1), p3(1,1);
	Path path;
	path.pushPos(p1);
	path.pushPos(p2);
	path.pushPos(p3);
	
	Unit *unit = new Unit(10, 15, 20, 25, 30, 35, p0);
	
	cout << m->isValidPath(unit, path) << endl;
	
	return 0;
}

#include <iostream>
#include "map.h"

using namespace std;

int main()
{
	Map m;
	
	Position p0(3,0), p1(0,0), p2(0,1), p3(1,1);
	Path path;
	path.pushPos(p1);
	path.pushPos(p2);
	path.pushPos(p3);
	
	Unit unit(10, p0);
	
	cout << m.isValidPath(&unit, path) << endl;
	
	return 0;
}

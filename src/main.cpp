#include <iostream>
#include "map.h"

using namespace std;

int main()
{
	Map m;
	
	Position p1(0,0), p2(0,1), p3(1,1);
	Path path;
	path.pushPos(p1);
	path.pushPos(p2);
	path.pushPos(p3);
	
	cout << m.isValidPath(path) << endl;
	
	return 0;
}

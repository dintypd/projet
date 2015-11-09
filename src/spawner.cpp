/**
 * @file spawner.cpp
 * @author A. Perhirin B. Le Clère
 * @since 06/11/2015
 * @brief implémentation des méthodes de la classe Spawner
 *
**/

#include "spawner.h"
#include "unit.h"

using namespace std;

Spawner::Spawner(Unit* prototype) 
: _prototype(prototype)
{}

Unit* Spawner::spawnUnit()
{
	return _prototype->clone();
}

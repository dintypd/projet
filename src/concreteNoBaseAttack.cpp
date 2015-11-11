/**
 * @file concreteBaseAttack.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de l'attaque de base des unités qui n'attaquent pas
 *
**/

#include "concreteNoBaseAttack.h"
#include "position.h"
#include "map.h"
#include <iostream>

using namespace std;

ConcreteNoBaseAttack::ConcreteNoBaseAttack(unsigned int ap) : Attack(ap)
{}

void ConcreteNoBaseAttack::attack(Position position, Map* map, Unit* attacker)
{
	cout << "Pas d'attaque" << endl;
}


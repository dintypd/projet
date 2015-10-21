/**
 * @file concretehplossspedef.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de la perte d'HP d'une unité défensive
 *
**/

#include "concretehplossspedef.h"
#include <iostream>
#include "unit.h"

using namespace std;

void ConcreteHPLossSpeDef::hpLoss(unsigned int value, Unit* u)
{
	u->setHP(u->getHP()-(value/2));
}


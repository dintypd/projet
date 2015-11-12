/**
 * @file attackable.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/11/2015
 * @brief implémentation des méthodes de la classe Attackable
**/

#include "attackable.h"
#include "hploss.h"

Attackable::Attackable(HPLoss* hpLoss) 
: _hpLoss(hpLoss)
{}

void Attackable::hpLoss(unsigned int value)
{
	_hpLoss->hpLoss(value, this);
}

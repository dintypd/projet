/**
 * @file concreteBaseAttackSpeBase.cpp
 * @author A. Perhirin B. Le Clère
 * @since 19/10/2015
 * @brief implémentation de l'attaque de base 
 *
**/

#include "concreteBaseAttackSpeBase.hpp"
#include "map.hpp"
#include "position.hpp"
#include "unit.hpp"
#include "base.hpp"

#include <iostream>

using namespace std;

ConcreteBaseAttackSpeBase::ConcreteBaseAttackSpeBase(unsigned int ap) : Attack(ap)
{}

void ConcreteBaseAttackSpeBase::attack(Position position, Map* map, Unit* attacker)
{
	// on cherche l'unité
	Unit* u = map->getUnitAt(position);
	Base* b = map->getBaseAt(position);
	
	if(u != 0 || b != 0)
	{
		if(attacker->getAP() >= _ap)
		{
			bool attack = false;
			
			// récupération des données
			unsigned int dmgs = attacker->getDmgs();

			// perte d'hp de  l'attaqué
			if(u != 0)
			{
				if(u->getPosition().distance(attacker->getPosition()) <= attacker->getRange())
				{
					u->hpLoss(dmgs);
					if(u->getHP() == 0)
					{
						map->die(u);
					}
					attack = true;
				}
				else
				{
					cout << "La cible est trop loin." << endl;
				}
			}
			else if(b != 0)
			{
				if(b->getPosition().distance(attacker->getPosition()) <= attacker->getRange())
				{
					dmgs *= 2;
					b->hpLoss(dmgs);
					attack = true;
				}
				else
				{
					cout << "La cible est trop loin." << endl;
				}
			}
			
			if(attack)
			{
				// perte d'ap de  l'attaquant
				attacker->setAP(attacker->getAP()-_ap);

				// affichage
				attacker->afficher();
				cout << "---> perd : " << _ap << " pa" << endl;
				cout << "---> pa : " << attacker->getAP() << "/" << attacker->getMaxAP() << endl;
				cout << "---> inflige : " << dmgs << " hp" << endl;
			}
		}
		else
		{
			cout << "L'unité n'a plus assez de pa : " << attacker->getAP() << " pa" << endl;
		}
	}
	else
	{
		// si on a pas trouvé d'unité à attaquer
		cout << "Rien à attaquer en ";
		position.afficher();
		cout << endl;
	}
}


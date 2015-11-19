/**
 * @file window.cpp
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Implémentation des méthodes de la classe Window
**/

#include "window.h"
#include "subject.h"
#include "tilemap.h"
#include "map.h"
#include "unit.h"
#include "data.h"
#include "player.h"
#include "game.h"
#include <iterator>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

Window::Window(Map* m) : _m(m), _window(sf::VideoMode(m->getSize()*50, m->getSize()*50), "The Game")
{
	_window.clear();
	_tiles = m->getTiles();
	_window.display();
}

void Window::quit()
{
	_window.close();
}

void Window::update(Subject* s)
{
	vector<Position> startingPositions = s->getData()->getStartingPositions_Map();
	map<unsigned int, Player*> *players = s->getMap()->getPlayers();
	_window.clear();
	
	//gestion de l'affichage de la map vide
	TileMap tileMap;
    if (!tileMap.load("tileset.png", sf::Vector2u(50, 50), _tiles, 12, 12))
    {
		cout << "Error : impossible de charger la map" << endl;
	}
	_window.draw(tileMap);
	
	//gestion de l'affichage des bases 
	sf::Sprite sbbase;
	sf::Texture bbase;
	sf::Sprite srbase;
	sf::Texture rbase;
	if (!bbase.loadFromFile("bluebase.png"))
	{
		cout << "Error : impossible de charger la bluebase" << endl;
	}
	sbbase.setTexture(bbase);
	if (!rbase.loadFromFile("redbase.png"))
	{
		cout << "Error : impossible de charger la redbase" << endl;
	}
	srbase.setTexture(rbase);	
	sbbase.setPosition(startingPositions[0].getX()*50, startingPositions[0].getY()*50);
	srbase.setPosition(startingPositions[1].getX()*50, startingPositions[1].getY()*50);
	_window.draw(sbbase);
	_window.draw(srbase);
	
	//gestion de l'affichage des unités
	map<unsigned int, Unit*> *blueUnits = players->at(0)->getUnits();
	map<unsigned int, Unit*> *redUnits = players->at(1)->getUnits();
	if ( blueUnits->size() > 0 )
	{
		sf::Texture barcher;
		sf::Texture bknight;
		if (!barcher.loadFromFile("bluearcher.png"))
		{
			cout << "Error : impossible de charger le bluearcher" << endl;
		}
		if (!bknight.loadFromFile("blueknight.png"))
		{
			cout << "Error : impossible de charger le blueknight" << endl;
		}
		map<unsigned int, Unit*>::iterator it;
		for (it = blueUnits->begin(); it != blueUnits->end(); ++it)
		{
			sf::Sprite sunit;
			if ( it->second->getImage() == "archer.png" )
			{
				sunit.setTexture(barcher);
			}
			else
			{
				sunit.setTexture(bknight);
			}
			sunit.setPosition(it->second->getPosition().getX()*50, it->second->getPosition().getY()*50);
			_window.draw(sunit);
		}
	}
	if ( redUnits->size() > 0 )
	{
		sf::Texture rarcher;
		sf::Texture rknight;
		if (!rarcher.loadFromFile("redarcher.png"))
		{
			cout << "Error : impossible de charger le redarcher" << endl;
		}
		if (!rknight.loadFromFile("redknight.png"))
		{
			cout << "Error : impossible de charger le redknight" << endl;
		}		
		map<unsigned int, Unit*>::iterator it;
		for (it = redUnits->begin(); it != redUnits->end(); ++it)
		{
			sf::Sprite sunit;
			if ( it->second->getImage() == "archer.png" )
			{
				sunit.setTexture(rarcher);
			}
			else
			{
				sunit.setTexture(rknight);
			}
			sunit.setPosition(it->second->getPosition().getX()*50, it->second->getPosition().getY()*50);
			_window.draw(sunit);
			
		}				
	}
	
	//gestion des numéros de ligne/colone
	sf::Font font;
	if (!font.loadFromFile("monof55.ttf"))
	{
		cout << "Error : impossible de charger la police" << endl;
	}
	
	for (unsigned int i = 0; i < _m->getSize(); ++i)
	{
		sf::Text ti;
		sf::Text tj;
		ti.setFont(font);
		tj.setFont(font);
		string num = to_string(i);
		ti.setString(num);
		tj.setString(num);
		ti.setCharacterSize(11);
		tj.setCharacterSize(11);
		ti.setPosition(50*i+25, 0);
		tj.setPosition(0, 50*i+25);
		_window.draw(ti);
		_window.draw(tj);
		
	}
	
	_window.display();
}


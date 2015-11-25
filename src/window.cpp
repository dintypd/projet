/**
 * @file window.cpp
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Implémentation des méthodes de la classe Window
**/

#include "window.hpp"
#include "subject.hpp"
#include "tilemap.hpp"
#include "map.hpp"
#include "unit.hpp"
#include "data.hpp"
#include "base.hpp"
#include "player.hpp"
#include "game.hpp"
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
    if (!tileMap.load("images/tileset.png", sf::Vector2u(50, 50), _tiles, 12, 12))
    {
		cout << "Error : impossible de charger la map" << endl;
	}
	_window.draw(tileMap);
	
	//chargement de la police
	sf::Font font;
	if (!font.loadFromFile("font/monof55.ttf"))
	{
		cout << "Error : impossible de charger la police" << endl;
	}
	
	//gestion de l'affichage des bases 
	sf::Sprite sbbase;
	sf::Texture bbase;
	sf::Sprite srbase;
	sf::Texture rbase;
	if (!bbase.loadFromFile("images/bluebase.png"))
	{
		cout << "Error : impossible de charger la bluebase" << endl;
	}
	sbbase.setTexture(bbase);
	if (!rbase.loadFromFile("images/redbase.png"))
	{
		cout << "Error : impossible de charger la redbase" << endl;
	}
	srbase.setTexture(rbase);	
	sbbase.setPosition(startingPositions[0].getX()*50, startingPositions[0].getY()*50);
	srbase.setPosition(startingPositions[1].getX()*50, startingPositions[1].getY()*50);
	_window.draw(sbbase);
	_window.draw(srbase);
	
	//gestion de l'affichage des unités
	map<unsigned int, Unit*> *blueUnits = players->at(1)->getUnits();
	map<unsigned int, Unit*> *redUnits = players->at(2)->getUnits();
	if ( blueUnits->size() > 0 )
	{
		sf::Texture barcher;
		sf::Texture bknight;
		if (!barcher.loadFromFile("images/bluearcher.png"))
		{
			cout << "Error : impossible de charger le bluearcher" << endl;
		}
		if (!bknight.loadFromFile("images/blueknight.png"))
		{
			cout << "Error : impossible de charger le blueknight" << endl;
		}
		map<unsigned int, Unit*>::iterator it;
		for (it = blueUnits->begin(); it != blueUnits->end(); ++it)
		{
			//affichage ID
			sf::Text id;
			id.setFont(font);
			string sid = to_string(it->second->getId());
			id.setString(sid);
			id.setCharacterSize(11);
			
			//affichage HP
			sf::Text hp;
			hp.setFont(font);
			string shp = to_string(it->second->getHP()) + "/" + to_string(it->second->getMaxHP());
			hp.setString(shp);
			hp.setCharacterSize(11);
			
			//affichage unité
			sf::Sprite sunit;
			if ( it->second->getImage() == "archer.png" )
			{
				sunit.setTexture(barcher);
			}
			else
			{
				sunit.setTexture(bknight);
			}
			id.setPosition(it->second->getPosition().getX()*50, it->second->getPosition().getY()*50);		//position ID
			hp.setPosition(it->second->getPosition().getX()*50+25, it->second->getPosition().getY()*50+40);	//position HP				
			sunit.setPosition(it->second->getPosition().getX()*50, it->second->getPosition().getY()*50);	//position unité
			_window.draw(sunit);
			_window.draw(id);
			_window.draw(hp);
		}
	}
	if ( redUnits->size() > 0 )
	{
		sf::Texture rarcher;
		sf::Texture rknight;
		if (!rarcher.loadFromFile("images/redarcher.png"))
		{
			cout << "Error : impossible de charger le redarcher" << endl;
		}
		if (!rknight.loadFromFile("images/redknight.png"))
		{
			cout << "Error : impossible de charger le redknight" << endl;
		}		
		map<unsigned int, Unit*>::iterator it;
		for (it = redUnits->begin(); it != redUnits->end(); ++it)
		{
			//affichage ID
			sf::Text id;
			id.setFont(font);
			string sid = to_string(it->second->getId());
			id.setString(sid);
			id.setCharacterSize(11);
			
			//affichage HP
			sf::Text hp;
			hp.setFont(font);
			string shp = to_string(it->second->getHP()) + "/" + to_string(it->second->getMaxHP());
			hp.setString(shp);
			hp.setCharacterSize(11);
			
			//affichage unité
			sf::Sprite sunit;
			if ( it->second->getImage() == "archer.png" )
			{
				sunit.setTexture(rarcher);
			}
			else
			{
				sunit.setTexture(rknight);
			}
			id.setPosition(it->second->getPosition().getX()*50, it->second->getPosition().getY()*50);		//position ID
			hp.setPosition(it->second->getPosition().getX()*50+25, it->second->getPosition().getY()*50+40);	//position HP									
			sunit.setPosition(it->second->getPosition().getX()*50, it->second->getPosition().getY()*50);	//position unité
			_window.draw(sunit);
			_window.draw(id);
			_window.draw(hp);
			
		}				
	}
	//gestion affichage nom des joueurs et HP bases
	sf::Text blueside;
	sf::Text redside;
	blueside.setFont(font);
	redside.setFont(font);
	string sblueside = "J1 : " + players->at(1)->getName() + "\n" + "HP base : " + to_string(players->at(1)->getBase()->getHP()) + "/" + to_string(players->at(1)->getBase()->getMaxHP());
	string sredside = "J2 : " + players->at(2)->getName() + "\n" + "HP base : " + to_string(players->at(2)->getBase()->getHP()) + "/" + to_string(players->at(2)->getBase()->getMaxHP());
	blueside.setString(sblueside);
	redside.setString(sredside);
	blueside.setCharacterSize(14);
	redside.setCharacterSize(14);
	blueside.setPosition(20, 15);
	redside.setPosition(450, 15);
	_window.draw(blueside);
	_window.draw(redside);
	
	//gestion des numéros de ligne/colone
	
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


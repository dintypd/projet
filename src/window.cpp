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
#include "game.h"
#include <iostream>
#include <vector>

using namespace std;

Window::Window(Map* m) : _m(m), _window(sf::VideoMode(m->getSize()*50, m->getSize()*50), "The Game")
{
	_window.clear();
	
	//gestion de l'affichage de la map vide
	_tiles = m->getTiles();
	TileMap tileMap;
    if (!tileMap.load("tileset.png", sf::Vector2u(50, 50), _tiles, 12, 12))
    {
		cout << "Error : impossible de charger la map" << endl;
	}
	_window.draw(tileMap);
	
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

void Window::quit()
{
	_window.close();
}

void Window::update(Subject* s)
{
	//Map* map = s->getData();
	_window.clear();
	
	//gestion de l'affichage de la map vide
	TileMap tileMap;
    if (!tileMap.load("tileset.png", sf::Vector2u(50, 50), _tiles, 12, 12))
    {
		cout << "Error : impossible de charger la map" << endl;
	}
	_window.draw(tileMap);
	
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


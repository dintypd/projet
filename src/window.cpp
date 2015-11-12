/**
 * @file window.cpp
 * @author B. Le Clère A.Perhirin
 * @since 11/11/2015
 * @brief Implémentation des méthodes de la classe Window
**/

#include "window.h"
#include "subject.h"
#include "tilemap.h"
#include <vector>

using namespace std;

Window::Window(Game* g)
: _window(sf::VideoMode(g->getData()->getSize()*50, g->getData()->getSize()*50), "The Game")
{
	_window.clear();
	_tiles = g->getData()->getTiles_Map();
	TileMap tileMap;
    if (!tileMap.load("tileset.png", sf::Vector2u(50, 50), _tiles, 12, 12))
        return -1;
	_window.draw(map);
	_window.display();
}

void Window::quit()
{
	_window.close();
}

void Window::update(Subject* s)
{
	Map* map = s->getData();
	if(color[0] == "/quit")
	{
		quit();
	}
	else
	{
		_window.clear();
		_window.display();
	}
}


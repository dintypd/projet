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
#include <vector>

using namespace std;

Window::Window(Game* g) : _g(g), _window(sf::VideoMode(g->getData()->getSize()*50, g->getData()->getSize()*50), "The Game")
{
	_window.clear();
	_tiles = g->getData()->getTiles();
	TileMap tileMap;
    if (!tileMap.load("tileset.png", sf::Vector2u(50, 50), _tiles, 12, 12))
    {
		//error
	}
	_window.draw(tileMap);
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
	_window.display();
}


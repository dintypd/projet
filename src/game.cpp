/**
 * @file game.cpp
 * @author A. Perhirin B. Le Clère
 * @since 03/11/2015
 * @brief implémentation des méthodes de la classe Game
 *
**/

#include "game.hpp"
#include "map.hpp"
#include "base.hpp"
#include "window.hpp"
#include "player.hpp"
#include "data.hpp"
#include "unit.hpp"
#include "knight.hpp"
#include "spawner.hpp"
#include "path.hpp"
#include "position.hpp"
#include "observer.hpp"

#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

Game::Game() 
: _turn(0)
, _end(false)
{
	_data = new Data;
	_map = new Map(_data->getTiles_Map(), _data->getStartingPositions_Map());
	Base* base;
	Player* player;
	Player* previous = 0;
	string name;
	
	// génération des bases et joueurs en fonction du nombre de slot de départ disponible
	for(int i = 0; i < _data->getStartingPositions_Map().size(); ++i)
	{
		base = new Base(_data->getUnsignedIntData_Base()["hp"], _data->getUnsignedIntData_Base()["summonRange"], _data->getUnsignedIntData_Base()["buildRange"], _data->getHPLossBehavior_Base(), _data->getStartingPositions_Map()[i]);	
		cout << "Nom du joueur " << i+1 << " ?" << endl;
		cin >> name;
		player = new Player(name, _data->getGolds_Player(), base);
		base->setPlayer(player);
		player->setNext(previous);
		previous = player;
		_map->addPlayer(player);
	}
	
	// on boucle la boucle des joueurs
	player = _map->getPlayers()->at(1);
	player->setNext(previous);
	_currentPlayer = player;
	

	// on lance le jeu
	play();
}

Game::~Game()
{
	delete(_data);
	delete(_map);
}

void Game::play()
{
	bool endGame = false;
	// les variables utiles pour la gestion des commandes
	string command;
	vector<string> commandSplit;
	
	cin.ignore();
	
	Window* w = new Window(_map);
	addObs(w);
	notifyObs();
	// la boucle du jeu
	while(!endGame)
	{	
		// on affiche qui doit jouer et un message d'aide
		cout << "C'est à " << _currentPlayer->getName() << " de jouer !" << endl;
		cout << "///// Tapez /help pour ouvrir le menu d'aide /////" << endl;
		
		// on récupère la commande tapée
		getline(cin, command);
		istringstream iss(command);
		copy(istream_iterator<string>(iss),
			 istream_iterator<string>(),
			 back_inserter(commandSplit));
			 
		// on boucle tant que le joueur courant ne passe pas son tour
		while(commandSplit[0] != "/end" && !endGame)
		{
			if(commandSplit[0] == "/help")
			{
				helpCommand();
			}
			else if(commandSplit[0] == "/quit")
			{
				quitCommand();
				notifyObs();
			}
			else if(commandSplit[0] == "/summon" && (commandSplit.size() == 1 || commandSplit.size() == 4))
			{
				summonCommand(commandSplit);
				notifyObs();
			}
			else if(commandSplit[0] == "/units")
			{
				unitsCommand();
			}
			else if(commandSplit[0] == "/golds")
			{
				goldsCommand();
			}
			else if(commandSplit[0] == "/infos" && commandSplit.size() == 2)
			{
				infosCommand(commandSplit);
			}
			else if(commandSplit[0] == "/move" && commandSplit.size() == 3)
			{
				moveCommand(commandSplit);
				notifyObs();
			}
			else if(commandSplit[0] == "/attack" && commandSplit.size() == 4)
			{
				attackCommand(commandSplit);
				notifyObs();
			}
			else
			{
				cout << "Commande invalide, tapez /help pour avoir toutes les commandes." << endl;
			}
			
			cout << endl;
			
			// on réinitialise la commande
			commandSplit.clear();
				
			_map->baseBreak();
			
			endGame = endOfGame();
			
			if(!endGame)
			{
				// on redemande une commande
				getline(cin, command);
				istringstream iss(command);
				copy(istream_iterator<string>(iss),
					 istream_iterator<string>(),
					 back_inserter(commandSplit));
			}
		}
		endTurn();
		
		
		// on réinitialise la commande
		commandSplit.clear();
	}
}

void Game::endTurn()
{
	++_turn;
	_currentPlayer->endTurn();
	_currentPlayer = _currentPlayer->getNext();
}

bool Game::endOfGame()
{
	if(_map->getPlayers()->size() == 1)
	{
		cout << _map->getWinner()->getName() << " a gagné la partie !" << endl;
		return true;
	}
	return _end;
}

void Game::helpCommand()
{
	cout << "Aide: les commandes disponibles sont :" << endl;
	cout << "- /help                           : affiche l'aide du jeu" << endl;
	cout << "- /units						   : récapitulatif des unités" << endl;
	cout << "- /golds						   : affiche la quantité d'argent disponible" << endl;
	cout << "- /infos    [ID_unité]            : affiche des informations sur une unité" << endl;
	cout << "- /summon                         : affiche la liste des classes disponibles" << endl;
	cout << "- /summon  [NOM_unité] [position] : invoque l'unité à la position donnée" << endl;
	cout << "- /move    [ID_unité]  {z|q|s|d}* : déplace l'unité selon la chaine de déplacement" << endl;
	cout << "- /attack  [ID_unité]  [position] : attaque l'unité à la position donnée" << endl;
	//cout << "- /upgrade [NOM_unité]            : affiche les améliorations disponibles pour l'unité" << endl;
	//cout << "- /upgrade [ID_unité]  [upgrade]  : améliore l'unité en fonction de l'upgrade donnée" << endl;
	cout << "- /end                            : termine le tour de jeu" << endl;
	cout << "- /quit                           : quitte le jeu" << endl;
}

void Game::quitCommand()
{
	cout << "Merci d'avoir joué !" << endl;
	_end = true;
}

void Game::summonCommand(vector<string> command)
{
	if(command.size() == 1)
	{
		cout << "Les classes disponibles sont :" << endl;
		for(auto classe : _data->getClasses())
		{
			cout << "- " << classe << endl;
		}
	}
	else
	{
		// on parse la commande
		string classe = command[1];
		unsigned int x = stoi(command[2]);
		unsigned int y = stoi(command[3]);

		if(_data->isClasse(classe))
		{
			Position p(x, y);
			if(_map->isValidSummonPosition(p, _currentPlayer))
			{
				Spawner* sp = _data->getSpawner(command[1]);
				
				if(sp->getCost() <= _currentPlayer->getGolds())
				{
					Unit* u = sp->spawnUnit(p);
					_currentPlayer->summon(u);
					cout << _currentPlayer->getName() << " invoque : ";
					u->afficher();
					cout << "---> perd : " << u->getCost() << " golds" << endl;
					cout << "---> golds : " << _currentPlayer->getGolds() << endl;
				}
				else
				{
					cout << "Vous n'avez pas assez d'argent pour invoquer cette unité." << endl;
				}
			}
			else
			{
				cout << "Impossible d'invoquer une unité en ";
				p.afficher();
				cout << endl;
			}
		}
		else
		{
			cout << "La classe " << classe << " n'existe pas." << endl;
		}
	}
}

void Game::unitsCommand()
{
	map<unsigned int, Player*>::iterator it;
	for (it = _map->getPlayers()->begin(); it != _map->getPlayers()->end(); ++it)
	{
		cout << it->second->getName() << " :" << endl;
		it->second->afficheUnits();
	}
}

void Game::goldsCommand()
{
	_currentPlayer->afficheGolds();
}

void Game::infosCommand(vector<string> command)
{
	unsigned int id = stoi(command[1]);
	if(_map->isUnit(id))
	{
		_map->getUnit(id)->afficherInfos();
	}
	else
	{
		cout << "Cette unité n'existe pas." << endl;
	}
}

void Game::moveCommand(vector<string> command)
{
	unsigned int id = stoi(command[1]);
	string strPath = command[2];
	
	Unit* u = _currentPlayer->getUnit(id);
	
	if(u != 0)
	{
		bool valid = true;
		Path* path = new Path;
		Position p = u->getPosition();

		for(auto c : strPath)
		{
			if(c == 'z' && p.getY() > 0)
			{
				p = p.up();
			}
			else if(c == 's' && p.getY() < _map->getSize()-1)
			{
				p = p.down();
			}
			else if(c == 'q' && p.getX() > 0)
			{
				p = p.left();
			}
			else if(c == 'd' && p.getX() < _map->getSize()-1)
			{
				p = p.right();
			}
			else
			{
				valid = false;
			}
			if(valid)
			{
				path->pushPos(p);
			}
		}

		if(valid)
		{
			u->move(path, _map);
		}
		else
		{
			cout << "Le chemin choisi est invalide." << endl;
		}
	}
	else
	{
		cout << "Cette unité n'existe pas." << endl;
	}
}

void Game::attackCommand(vector<string> command)
{
	unsigned int id = stoi(command[1]);
	unsigned int x = stoi(command[2]);
	unsigned int y = stoi(command[3]);
	Position p(x, y);
	
	Unit* u = _currentPlayer->getUnit(id);
	
	if(u != 0)
	{
		u->attack(p, _map);
	}
	else
	{
		cout << "Cette unité n'existe pas." << endl;
	}
}

Data* Game::getData()
{
	return _data;
}

Map* Game::getMap()
{
	return _map;
}

void Game::addObs(Observer* o)
{
	_obs.push_back(o);
}

void Game::rmObs(Observer* o)
{
	iterator it = std::find(_obs.begin(), _obs.end(), o);
	if(it != _obs.end())
		_obs.erase(it);
}

void Game::notifyObs()
{
	for(auto o : _obs)
	{
		o->update(this);
	}
}

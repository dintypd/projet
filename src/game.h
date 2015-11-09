/**
 * @file game.h
 * @author B. Le Clère, A. Perhirin
 * @since 03/11/2015
 * @brief Définition de la classe game
**/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Data;
class Player;
class Map;
class Unit;
class Position;
/**
 * @class Game game.h
 * 
 * @brief Classe qui centralisera tout le jeu
 */
class Game
{
	private: 
		Data* _data;
		unsigned int _turn;
		Player* _currentPlayer;
		Map* _map;
	public:
		Game();
		void play();
		void endTurn();
		void helpCommand();
		void quitCommand();
		void summonCommand(std::vector<std::string> command);
		void unitsCommand();
		void goldsCommand();
		Unit* createUnit(std::string classe, Position p);
};

#endif // GAME_H

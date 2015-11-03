/**
 * @file game.h
 * @author B. Le Clère, A. Perhirin
 * @since 03/11/2015
 * @brief Définition de la classe game
**/

#ifndef GAME_H
#define GAME_H

class Player;
class Map;
/**
 * @class Game game.h
 * 
 * @brief Classe qui centralisera tout le jeu
 */
class Game
{
	private: 
		unsigned int _turn;
		Player* _currentPlayer;
		Map* _map;
	public:
		Game();
		void endTurn();
};

#endif // GAME_H

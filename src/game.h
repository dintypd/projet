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
		/**
		 * @brief constructeur
		 */
		Game();

		/**
		 * @brief Boucle du jeu, fini lorsque la commande tapée est /quit
		 */
		void play();

		/**
		 * @brief Méthode centralisant toutes les actions à effectuer à la fin du tour
		 */
		void endTurn();

		/**
		 * @brief Actions lors de la détection de /help
		 */
		void helpCommand();

		/**
		 * @brief Actions lors de la détection de /quit
		 */
		void quitCommand();

		/**
		 * @brief Actions lors de la détection de /summon
		 */
		void summonCommand(std::vector<std::string> command);

		/**
		 * @brief Actions lors de la détection de /units
		 */
		void unitsCommand();

		/**
		 * @brief Actions lors de la détection de /golds
		 */
		void goldsCommand();

		/**
		 * @brief Actions lors de la détection de /infos
		 */
		void infosCommand(std::vector<std::string> command);

		/**
		 * @brief Actions lors de la détection de /move
		 */
		void moveCommand(std::vector<std::string> command);

		/**
		 * @brief Actions lors de la détection de /attack
		 */
		void attackCommand(std::vector<std::string> command);
};		

#endif // GAME_H

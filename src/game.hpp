/**
 * @file game.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 03/11/2015
 * @brief Définition de la classe game
**/

#ifndef GAME_HPP
#define GAME_HPP

#include "subject.hpp"

#include <list>
#include <vector>
#include <iterator>
#include <string>

class Data;
class Player;
class Map;
class Unit;
class Position;

/**
 * @class Game game.hpp
 * 
 * @brief Classe qui centralisera tout le jeu
 */
class Game : public Subject
{
	private: 
		Data* _data;
		unsigned int _turn;
		bool _end;
		Player* _currentPlayer;
		Map* _map;
		std::list<Observer*> _obs;
		typedef std::list<Observer*>::iterator iterator; 
		typedef std::list<Observer*>::const_iterator const_iterator;
		
	public:
		/**
		 * @brief constructeur
		 */
		Game();
		
		/**
		 * @brief destructeur
		 */
		 ~Game();

		/**
		 * @brief Boucle du jeu, fini lorsque la commande tapée est /quit
		 */
		void play();

		/**
		 * @brief Méthode centralisant toutes les actions à effectuer à la fin du tour
		 */
		void endTurn();
		 
		/**
		 * @brief Méthode qui vérifie si un des joueurs à gagné
		 */
		bool endOfGame();

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
		
		/**
		 * @brief Ajout d'un poiteur vers observateur à la liste obs
		 * @param o un pointeur vers observateur
		 */
		void addObs(Observer* o);

		/**
		 * @brief La suppression d'un pointeur vers observateur de la liste obs, s'il existe
		 * @param o un pointeur vers observateur
		 */
		void rmObs(Observer* o);

		/**
		 * @brief Notifie à tous les observateurs de la liste obs que cette classe a changé
		 */
		void notifyObs();
		
		/**
		 * @brief Retourne les data pour l'observer Window
		 */
		 Data* getData();
		 
		 /**
		 * @brief Retourne la map pour l'observer Window
		 */
		 Map* getMap();
};		

#endif // GAME_HPP

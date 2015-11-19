/**
 * @file map.h
 * @author B. Le Clère, A. Perhirin
 * @since 07/10/2015
 * @brief Définition de la classe Map
**/

#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
#include "position.h"

class Decor;
class Player;
class Unit;
class Path;
class Base;

/**
 * @class Map map.h
 * 
 * @brief Classe permettant l'utilisation d'une map
 */
class Map
{
	private:
		unsigned int _size;
		std::vector<Decor*> _decors;
		std::vector<std::vector<unsigned int>> _tiles;
		std::vector<Position> _startingPositions;
		std::map<unsigned int, Player*> _players;
		//std::vector<Objective> objectives;
		
	public:
		/**
		 * @brief Constructeur
		 */
		Map(std::vector<std::vector<unsigned int>> tiles, 
			std::vector<Decor*> decors, 
			std::vector<Position> startingPositions);
		
		/**
		 * @brief Méthode qui teste si un chemin est valide pour une unité donnée
		 * @param unit l'unité permetant de savoir l'emplacement de départ du chemin
		 * @param path le chemin à tester
		 * @return vrai si le chemin est valide
		 */
		bool isValidPath(Unit* unit, Path* path) const;
		
		/**
		 * @brief Méthode qui teste si une ligne de vue est valide pour une unité donnée
		 * @param unit l'unité permetant de savoir l'emplacement de départ de l'action
		 * @param position la position ou l'action doit être effectuée
		 * @return vrai si la ligne de vue est valide
		 */
		bool isValidViewLine(Unit* unit, Position position) const;
		
		/**
		 * @brief Méthode qui teste si une unité peut être invoquée à la position donnée
		 * @param position la position d'invocation
		 * @param player le joueur qui invoque
		 * @return vrai si l'unité peut être invoquée à la position p
		 */
		bool isValidSummonPosition(Position position, Player* player) const;
		
		/**
		 * @brief Méthode qui retourne le tableau de tiles
		 * @return le tableau des tiles
		 */		
		std::vector<std::vector<unsigned int>> getTiles() const;
		
		/**
		 * @brief Méthode qui retourne une unité présente à une position donnée
		 * @param position la position à laquelle on va récupèrer l'unité
		 * @return l'unité présente à la position donnée
		 */
		Unit* getUnitAt(Position position) const;
		
		/**
		 * @brief Accesseur de l'unité en fonction de son identifiant
		 * @param id l'identifiant de l'unité
		 * @return l'unité qui possède id comme identifiant
		 */
		Unit* getUnit(unsigned int id) const;
		
		/**
		 * @brief Permet de savoir si une unité existe
		 * @param id l'identifiant de l'unité
		 * @return vrai si l'unité existe
		 */
		 bool isUnit(unsigned int id) const;
		
		/**
		 * @brief Méthode testant la présence d'une unité à une position donnée
		 * @param position la position a laquelle on veut savoir si une unité est présente
		 * @return vrai s'il y a une unité à la position donnée
		 */
		bool isUnitAt(Position position) const;
		
		/**
		 * @brief Méthode qui retourne un décor présent à une position donnée
		 * @param position la position à laquelle on va récupèrer le décor
		 * @return le décor présent à la position donnée
		 */
		Decor* getDecorAt(Position position) const;
		
		/**
		 * @brief Méthode testant la présence d'un décor à une position donnée
		 * @param position la position a laquelle on veut savoir si un décor est présent
		 * @return vrai s'il y a un décor à la position donnée
		 */
		bool isDecorAt(Position position) const;
		
		/**
		 * @brief Méthode qui retourne la base à la position donnée
		 * @param position la position
		 * @return la base
		 */
		Base* getBaseAt(Position position) const;
		
		/**
		 * @brief Méthode qui teste si une base est présente à la position donnée
		 * @param position la position
		 * @return vrai si il y a une base
		 */
		bool isBaseAt(Position position) const;
		
		/**
		 * @brief Ajoute un joueur sur la map
		 * @param player le joueur à ajouté
		 */
		void addPlayer(Player* player);
		
		/**
		 * @brief Accesseur de la map des joueurs
		 * @return une map id -> joueur contenant tous les joueurs
		 */
		std::map<unsigned int, Player*> * getPlayers();

		/**
		 * @brief Accesseur de la taille de la map
		 * @return un unsigned int
		 */
		unsigned int getSize() const;
		
		bool isBlocked(Position position) const;
};
 
#endif // MAP_H



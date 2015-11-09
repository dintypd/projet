/**
 * @file player.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Player
**/

#ifndef PLAYER_H
#define PLAYER_H

#include <map>

class Position;
class Unit;
class Base;
/**
 * @class Player player.h
 * 
 * @brief Classe définissant un joueur
 */
class Player
{
	private:
		std::string _name;
		unsigned int _id; // identifiant unique
		static unsigned int _nextId; // le prochain objet aura cet identifiant + 1
		Base *_base;
		std::map<unsigned int, Unit*> _units;
		unsigned int _golds;
		Player* _next; // le joueur qui jouera après ce joueur
		
	public:
		/**
		 * @brief Constructeur
		 */
		Player(std::string name, unsigned int golds, Base* base);
		
		/**
		 * @brief Accesseur de l'identifiant
		 * @return l'identifiant du joueur
		 */
		unsigned int getId() const;
		
		/**
		 * @brief Accesseur du nom 
		 * @return le nom du joueur
		 */
		std::string getName() const;
		
		/**
		 * @brief Accesseur du nombre de golds
		 * @return le nombre de golds du joueur
		 */ 
		unsigned int getGolds() const;
		
		/** 
		 * @brief Accesseur du tableau des unités
		 * @return le tableau des unités du joueur
		 */
		std::map<unsigned int, Unit*> * getUnits();
		
		/**
		 * @brief Accesseur de la base
		 * @return la base du joueur
		 */
		Base* getBase() const;
		
		/**
		 * @brief Méthode qui permet à un joueur d'invoquer une unité donnée à une position donnée
		 * @param unit l'unité 
		 * @param position la position voulue
		 */
		void summon(Unit* unit/*, Position position*/);
		
		/**
		 * @brief Méthode qui crédite l'argent d'un joueur de la somme donnée
		 * @param golds la somme à créditer
		 */
		void addGolds(unsigned int golds);
		
		/**
		 * @brief Méthode qui débite l'argent d'un joueur de la somme donnée
		 * @param golds la somme à débiter
		 * 
		 * @pre (_golds - golds >= 0)
		 */
		void rmGolds(unsigned int golds);
		
		/**
		 * @brief Méthode qui affiche la quantité d'argent du joueur
		 */
		void afficheGolds();
		
		/**
		 * @brief Modifie le joueur suivant dans l'ordre du jeu
		 * @param next le joueur qui jouera après "this"
		 */
		void setNext(Player* next);
		
		/**
		 * @brief Retourne le joueur suivant dans l'ordre du jeu
		 * @return le joueur qui jouera après "this"
		 */
		Player* getNext() const;
		
		/**
		 * @brief Retourne l'unité du joueur en fonction du paramètre
		 * @param id l'identifiant de l'unité choisie
		 */
		Unit* getUnit(unsigned int id) const;
		
		void afficheUnits();
};
 
#endif // PLAYER_H




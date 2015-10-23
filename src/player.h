/**
 * @file player.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Player
**/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

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
		unsigned int _id; // identifiant unique
		static unsigned int _nextId; // le prochain objet aura cet identifiant
		Base *_base;
		std::vector<Unit*> _units;
		unsigned int _golds;
		
	public:
		/**
		 * @brief Constructeur
		 */
		Player();
		
		/**
		 * @brief Accesseur de l'identifiant
		 * @return l'identifiant du joueur
		 */
		unsigned int getId() const;
		
		/**
		 * @brief Accesseur du nombre de golds
		 * @return le nombre de golds du joueur
		 */ 
		unsigned int getGolds() const;
		
		/** 
		 * @brief Accesseur du tableau des unités
		 * @return le tableau des unités du joueur
		 */
		std::vector<Unit*> getUnits() const;
		
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
		void summon(Unit unit, Position position);
		
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
};
 
#endif // PLAYER_H




/**
 * @file unit.h
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Unit
**/

#ifndef UNIT_H
#define UNIT_H

// #include "upgrade.h"
// #include "specialisation.h"
#include "position.h"

class Map;
class HPLoss;
class Attack;
class Move;
class Path;

/**
 * @class Unit unit.h
 * 
 * @brief Classe permettant l'utilisation d'unités
 */
class Unit
{
	private:
		unsigned int _id, 	// identifiant unique
			_range,			// portée d'attaque
			_ap, 			// Action Points
			_mp,			// Move Points
			_hp,			// Health Points
			_dmgs,			// Damages
			_cost;			// Coût 
		static unsigned int _nextId; // le prochain objet aura cet identifiant
		Position _position;		// Position actuelle
		// Upgrade *_upgrade;
		// Specialisation *_specialisation;
		Attack *_attack;
		HPLoss *_hpLoss;
		Move *_move;
		bool _summoner;		// unité peut invoquer près d'elle?
		bool _builder;		// unité peut construire?
		
	public:
		/**
		 * @brief Constructeur
		 * @param range La portée d'attaque
		 * @param ap Le nombre de points d'action
		 * @param mp Le nombre de points de mouvement
		 * @param hp Les points de vie
		 * @param dmgs Les dégâts que l'unité inflige
		 * @param cost Le coût en golds
		 * @param pos La position actuelle de l'unité (ici de spawn)
		 * @param summoner L'untié peut elle invoquer ?
		 * @param builder L'unité peut elle construire ?
		 */
		 Unit(  unsigned int range,
				unsigned int ap,
				unsigned int mp,
				unsigned int hp,
				unsigned int dmgs,
				unsigned int cost,
				Position position);
				
		/**
		 * @brief Accesseur de l'identifiant
		 * @return l'identifiant du décor
		 */
		unsigned int getId() const;
		
		/**
		 * @brief Accesseur de la position
		 * @return la position du décor
		 */
		Position getPosition() const;
		
		/**
		 * @brief Accesseur de la portée
		 * @return la portée d'attaque
		 */
		unsigned int getRange() const;
		
		/**
		 * @brief Accesseur des points d'action
		 * @return le nombre de PA
		 */
		unsigned int getAP() const;
		
		/**
		 * @brief Accesseur des points de mouvement
		 * @return le nombre de PM
		 */
		unsigned int getMP() const;
		
		/**
		 * @brief Accesseur des points de vie
		 * @return le nombre de HP 
		 */
		unsigned int getHP() const;
		
		/**
		 * @brief Accesseur des dommages
		 * @return les dommages
		 */
		unsigned int getDmgs() const;
		
		/**
		 * @brief Accesseur du coût
		 * @return le coût
		 */
		unsigned int getCost() const;
		
		/**
		 * @brief Accesseur de la capacité Summoner
		 * @return booléen V/F
		 */
		bool isSummoner() const;
		
		/**
		 * @brief Accesseur de la capacité Builder
		 * @return booléen V/F
		 */
		bool isBuilder() const;
		
		/**
		 * @brief Setter de portée
		 */
		void setRange( unsigned int range );
		
		/**
		 * @brief Setter de points d'action
		 */
		void setAP ( unsigned int ap );
		
		/**
		 * @brief Setter de points de mouvement
		 */
		void setMP ( unsigned int mp );
		
		/**
		 * @brief Setter de points de vie
		 */
		void setHP ( unsigned int hp );
		
		/**
		 * @brief Setter de dommages
		 */
		void setDmgs ( unsigned int dmgs );
		
		/**
		 * @brief Setter de positon
		 */
		void setPos ( Position pos );
		
		/**
		 * @brief Setter de capacité Summoner ( la rend TRUE )
		 */
		void setSummoner();		// A utiliser suite a une upgrade => rend toujours TRUE
		
		/**
		 * @brief Setter de capacité Builder ( la rend TRUE )
		 */
		void setBuilder(); 		// A utiliser suite a une upgrade => rend toujours TRUE

		/**
		 * @brief L'unité attaque la position pos
		 * @param pos La position à attaquer
		 * @param map La carte
		 */
		void attack ( Position pos, Map *map );
		
		/**
		 * @brief L'unité perd des points de vie
		 * @param value Le nomdre d'HP perdus
		 */
		void hpLoss ( unsigned int value );
		
		/**
		 * @brief Déplace l'unité 
		 * @param path Le chemin emprunté
		 * @param map La carte
		 */
		void move ( Path *path, Map *map );
};

#endif // UNIT_H			

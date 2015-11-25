/**
 * @file unit.hpp
 * @author B. Le Clère, A. Perhirin
 * @since 12/10/2015
 * @brief Définition de la classe Unit
**/

#ifndef UNIT_HPP
#define UNIT_HPP

#include "position.hpp"

#include <string>

class Map;
class HPLoss;
class Attack;
class Move;
class Path;

/**
 * @class Unit unit.hpp
 * 
 * @brief Classe permettant l'utilisation d'unités
 */
class Unit
{
	protected:
		unsigned int _id, 		// identifiant unique
					 _range,	// portée d'attaque
					 _ap,		// Action Points
					 _apMax, 	// Action Points Max
					 _mp,		// Move Points
					 _mpMax,    // Move Points Max
					 _hp,		// Health Points
					 _hpMax,	// Health Points Max
					 _dmgs,		// Damages
					 _cost;		// Coût 
		static unsigned int _nextId; // le prochain objet aura cet identifiant + 1
		Position _position;		// Position actuelle
		Attack *_attack;
		HPLoss *_hpLoss;
		Move *_move;
		bool _summoner;		// unité peut invoquer près d'elle?
		bool _builder;		// unité peut construire?
		std::string _image;		// image de l'unité
		
	public:
		/**
		 * @brief Constructeur
		 */
		 Unit(unsigned int range,
			  unsigned int ap,
			  unsigned int mp,
			  unsigned int hp,
			  unsigned int dmgs,
			  unsigned int cost,
			  Attack* attack,
			  HPLoss* hpLoss,
			  Move* move,
			  Position position,
			  std::string image);
			  
		/**
		 * @brief Destructeur (évite les warnings)
		 */
		//virtual ~Unit();
				
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

		unsigned int getMaxAP() const;
		
		/**
		 * @brief Accesseur des points de mouvement
		 * @return le nombre de PM
		 */
		unsigned int getMP() const;

		unsigned int getMaxMP() const;
		
		/**
		 * @brief Accesseur des points de vie
		 * @return le nombre de HP 
		 */
		unsigned int getHP() const;


		unsigned int getMaxHP() const;
		
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
		 * @brief Accesseur de l'image
		 * @return l'image
		 */
		std::string getImage() const;
		
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
		void setPosition ( Position pos );
		
		/**
		 * @brief Setter d'image
		 */
		void setImage ( std::string image );		
		
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
		
		/**
		 * @brief Méthode virtuelle qui affiche le nom de la classe de l'unité
		 */
		virtual std::string classe() const = 0;
		
		/**
		 * @brief Méthode qui affiche la classe de l'unité et sa position
		 */
		void afficher();
		
		/**
		 * @brief Méthode qui retourne une unité possèdant le même type, mais aussi les même caractéristiques que "this"
		 * @param position la position assignée à l'unité retournée
		 * @return un clone de "this"
		 */
		virtual Unit* clone(Position position) const = 0;

		/**
		 * @brief Affiche les infos de l'unité
		 */
		virtual void afficherInfos() const = 0;

		/**
		 * @brief Méthode qui éxécute les actions de fin de tour comme réinitialiser les pa et pm
		 */
		void endTurn();
};

#endif // UNIT_HPP	

/**
 * @file data.h
 * @author B. Le Clère, A. Perhirin
 * @since 03/11/2015
 * @brief Définition de la classe data
**/

#ifndef DATA_H
#define DATA_H

#include <map>
#include <vector>

class Decor;
class Position;
class HPLoss;
class Attack;
class ConcreteBaseAttack;
class ConcreteBaseAttackSpeBase;
class ConcreteHPLoss;
class ConcreteHPLossSpeDef;
class ConcreteMove;
class Move;
class Spawner;
/**
 * @class Data data.h
 * 
 * @brief Classe qui centralise toute les données du jeu
 */
class Data
{
	private: 
		// Comportements d'attaque possibles
		Attack* _baseAttack;
		Attack* _baseAttackSpeBase;
		unsigned int _attackAP;
		
		// Comportement de perte d'hp possibles
		HPLoss* _hpLoss;
		HPLoss* _hpLossSpeDef;
		
		// Comportements de déplacements possibles
		Move* _move;
		
		// Liste des spawner
		std::map<std::string, Spawner*> _spawnerList;
		
	public:
		Data();
		// Map data
		/**
		 * Méthode qui retourne un vector de vector qui correspond aux cases accessibles ou non de la map de base sans les décors
		 * @return un tableau de tableau de booleen
		 */
		std::vector<std::vector<unsigned int>> getTiles_Map();
		
		/**
		 * Retourne un vector des décors de la map
		 * @return un tableau de décors
		 */
		std::vector<Decor*> getDecors_Map();
		
		/**
		 * Retourne un vector contenant les positions de départ de la map
		 * @return un tableau de position
		 */
		std::vector<Position> getStartingPositions_Map();
		
		// Base data
		/**
		 * Retourne toutes les données de type unsigned int de la classe base afin d'initialiser les instances de celle-ci
		 * @return une map string->unsigned int
		 */
		std::map<std::string, unsigned int> getUnsignedIntData_Base();
		
		/**
		 * Retourne le comportement de perte d'hp des bases
		 */
		HPLoss* getHPLossBehavior_Base();
		
		// Spawner
		/**
		 * Retourne le spawner associé à la classe en paramètre
		 * @param classe la classe dont on veut le spawner
		 * @return un pointeur vers spawner
		 */
		Spawner* getSpawner(std::string classe);
		
		/**
		 * Méthode qui vérifie si une classe existe
		 * @param classe la classe dont on veut savoir si elle existe
		 * @return vrai si la classe est clé de la map _spawnerList
		 */
		bool isClasse(std::string classe);
		
		/**
		 * Accesseur de la liste des classes
		 * @return un tableau de string
		 */
		std::vector<std::string> getClasses();
		
		// Player data
		/**
		 * Retourne le nombre de golds des joueurs à l'initialisattion
		 * @return un unsigned int
		 */
		unsigned int getGolds_Player();
};

#endif // DATA_H

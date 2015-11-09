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
class ConcreteBaseAttackSpeTower;
class ConcreteHPLoss;
class ConcreteHPLossSpeDef;
class ConcreteMove;
class ConcreteNoBaseAttack;
class ConcreteNoMove;
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
		Attack* _baseAttackSpeTower;
		Attack* _noBaseAttack;
		
		// Comportement de perte d'hp possibles
		HPLoss* _hpLoss;
		HPLoss* _hpLossSpeDef;
		
		// Comportements de déplacements possibles
		Move* _move;
		Move* _noMove;
		
		// Liste des spawner
		std::map<std::string, Spawner*> _spawnerList;
		
	public:
		Data();
		// Map data
		std::vector<std::vector<bool>> getTiles_Map();
		std::vector<Decor*> getDecors_Map();
		std::vector<Position> getStartingPositions_Map();
		
		// Base data
		std::map<std::string, unsigned int> getUnsignedIntData_Base();
		
		// Spawner
		Spawner* getSpawner(std::string classe);
		
		// Player data
		unsigned int getGolds_Player();
		
		// Game data
		std::vector<std::string> getClassesData_Game();
};

#endif // DATA_H

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
		
	public:
		Data();
		// Map data
		std::vector<std::vector<bool>> getTiles_Map();
		std::vector<Decor*> getDecors_Map();
		std::vector<Position> getStartingPositions_Map();
		
		// Base data
		std::map<std::string, unsigned int> getUnsignedIntData_Base();
		
		// Knight data
		std::map<std::string, unsigned int> getUnsignedIntData_Knight();
		std::map<std::string, bool> getBoolData_Knight();
		Attack* getAttackBehavior_Knight();
		Move* getMoveBehavior_Knight();
		HPLoss* getHPLossBehavior_Knight();
};

#endif // DATA_H

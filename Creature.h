#ifndef Creature_h
#define Creature_h

#include <stdlib.h> 

class Creature {
	public:
		Creature(std::string);
		void step();
		void infect(Creature);
		void writeIdentifier();
		void addInstruction(std::string);
		void moveToNextTurn();
		void addToDarwin(Darwin&, std::pair<int, int>)
	private:
		bool hadTurn;
		int face;
		int currentStep;
		Darwin& grid;
		std::string identifier;
		std::pair<int, int> coordinates;
		std::vector<std::string> instructionSet;
}
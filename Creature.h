#ifndef CREATURE_H
#define CREATURE_H

#include "Species.h"
#include <stdlib.h> 
#include <utility>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Creature {
	public:
		Creature(Species type) : species(type) {};
		int getAction(int);
		void infect(Creature*);
		void printIdentifier();
		void addToDarwin(std::pair<int, int>);
		std::pair<int, int> getLocationFaced(std::pair<int, int>);
		enum Action {
			NONE,
			MOVE,
			INFECT
		};
	private:
		bool hadTurn;
		int face;
		unsigned currentStep;
		Species species;
}

#endif
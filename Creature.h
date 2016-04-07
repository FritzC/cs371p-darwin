#ifndef CREATURE_H
#define CREATURE_H

#include <stdlib.h> 
#include <utility>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Species.h"

class Creature {
	public:
		Creature(Species type) : species(type) {};
		void step(Darwin*);
		void infectWith(Species);
		void printIdentifier();
		void addToDarwin(std::pair<int, int>);
		std::pair<int, int> getLocationFaced();
	private:
		bool hadTurn;
		int face;
		unsigned currentStep;
		Species species;
		std::pair<int, int> location;
};

#endif
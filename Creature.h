#ifndef CREATURE_H
#define CREATURE_H

#include <stdlib.h> 
#include <utility>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Species.h"
#include "Darwin.h"

class Creature {
	public:
		Creature(Species);
		void step(Darwin&);
		void infectWith(Species);
		void printIdentifier();
		void addToDarwin(Darwin&, std::pair<int, int>)
	private:
		bool hadTurn;
		int face;
		int currentStep;
		std::pair<int, int> location;
};

#endif
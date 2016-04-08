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
		Creature(Species type, int facing) : face(facing), species(type) {};
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
		enum LocationType {
			INVALID,
			EMPTY,
			OCCUPIED
		};
		bool moved;
	private:
		int face;
		unsigned currentStep;
		Species species;
};

#endif
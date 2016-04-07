
#ifndef Darwin_h
#define Darwin_h

#include <stdlib.h>
#include <utility>
#include "Creature.h"

class Darwin {
	public:
		Darwin(int, int);
		void print();
		void step();
		void insertCreature(std::pair<int, int>);
		Creature* getCreatureAt(std::pair<int, int>);
		enum LocationType {
			INVALID,
			EMPTY,
			OCCUPIED
		};
		LocationType getLocationType(std::pair<int, int>);
	private:
		int width;
		int height;
		int turn;
		Creature*** grid;
}
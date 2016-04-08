#ifndef DARWIN_H
#define DARWIN_H

#include "Creature.h"
#include <stdlib.h>
#include <utility>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cassert>

class Darwin {
	public:
		Darwin(int, int);
		void print();
		void step();
		void insertCreature(Creature&, std::pair<int, int>);
		Creature* getCreatureAt(std::pair<int, int>);
		int getLocationType(std::pair<int, int>);
	private:
		int width;
		int height;
		int turn;
		Creature*** grid;
};

#endif
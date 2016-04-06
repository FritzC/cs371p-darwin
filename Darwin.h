
#ifndef Darwin_h
#define Darwin_h

#include <stdlib.h>

class Darwin {
	public:
		Darwin(int, int);
		bool isValidLoc(std::pair<int, int>);
		Creature* getCreatureAt(std::pair<int, int>);
	private:
		int width;
		int height;
		Creature** grid;
}
#ifndef DARWIN_H
#define DARWIN_H

#include "gtest/gtest_prod.h"
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
		int getLocationType(Creature*, std::pair<int, int>);
		Creature** begin();
		Creature** end();
		Creature* at(int);
	private:
		int width;
		int height;
		FRIEND_TEST(DarwinFixture, initDarwin1);
		FRIEND_TEST(DarwinFixture, initDarwin2);
		FRIEND_TEST(DarwinFixture, initDarwin3);
		int turn;
		FRIEND_TEST(DarwinFixture, initDarwin4);
		FRIEND_TEST(DarwinFixture, begin1);
		FRIEND_TEST(DarwinFixture, begin2);
		FRIEND_TEST(DarwinFixture, begin3);
		FRIEND_TEST(DarwinFixture, end1);
		FRIEND_TEST(DarwinFixture, end2);
		FRIEND_TEST(DarwinFixture, end3);
		FRIEND_TEST(DarwinFixture, at2);
		FRIEND_TEST(DarwinFixture, insertCreature1);
		FRIEND_TEST(DarwinFixture, insertCreature2);
		Creature** grid;
};

#endif
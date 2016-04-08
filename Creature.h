#ifndef CREATURE_H
#define CREATURE_H

#include "gtest/gtest_prod.h"
#include "Species.h"
#include <stdlib.h> 
#include <utility>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Creature {
	public:
		Creature() {};
		Creature(Species& type, int facing) : moved(false), face(facing), currentStep(0), species(&type) {};
		int getAction(int);
		void infect(Creature*);
		void printIdentifier();
		bool checkIfEnemy(Creature*);
		void resetTurn();
		std::pair<int, int> getLocationFaced(std::pair<int, int>);
		enum Action {
			NONE,
			MOVE,
			INFECT
		};
		enum LocationType {
			INVALID,
			EMPTY,
			OCCUPIED,
			ENEMY
		};
	private:
		FRIEND_TEST(DarwinFixture, resetTurn1);
		FRIEND_TEST(DarwinFixture, resetTurn2);
		bool moved;
		FRIEND_TEST(DarwinFixture, step1);
		FRIEND_TEST(DarwinFixture, step2);
		FRIEND_TEST(DarwinFixture, initCreature2);
		int face;
		FRIEND_TEST(DarwinFixture, initCreature3);
		FRIEND_TEST(DarwinFixture, getAction6);
		FRIEND_TEST(DarwinFixture, getAction7);
		unsigned currentStep;
		FRIEND_TEST(DarwinFixture, initCreature1);
		FRIEND_TEST(DarwinFixture, infect1);
		FRIEND_TEST(DarwinFixture, infect2);
		Species* species;
};

#endif
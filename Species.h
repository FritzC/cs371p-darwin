#ifndef SPECIES_H
#define SPECIES_H

#include "gtest/gtest_prod.h"
#include <stdio.h>
#include <string>
#include <vector>

class Species {
	public:
		Species(char id) : identifier(id) {};
		std::string getInstruction(unsigned);
		void addInstruction(std::string);
		void printIdentifier();
	private:
		FRIEND_TEST(DarwinFixture, initCreature1);
		FRIEND_TEST(DarwinFixture, initSpecies1);
		FRIEND_TEST(DarwinFixture, initSpecies2);
		char identifier;
		FRIEND_TEST(DarwinFixture, addInstruction1);
		FRIEND_TEST(DarwinFixture, addInstruction2);
		std::vector<std::string> instructionSet;
};
#endif
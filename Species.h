#ifndef SPECIES_H
#define SPECIES_H

#include <stdlib.h>
#include <string>
#include <vector>

class Species {
	public:
		Species(char id) : identifier(id) {};
		std::string getInstruction(int);
		void addInstruction(std::string);
		void printIdentifier();
	private:
		char identifier;
		std::vector<std::string> instructionSet;
};
#endif
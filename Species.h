#ifndef SPECIES_H
#define SPECIES_H

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
		char identifier;
		std::vector<std::string> instructionSet;
}
#endif
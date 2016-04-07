
#ifndef Species_h
#define Species_h

#include <stdlib.h>

class Species {
	public:
		Species(char id) : identifier(id);
		std::string getInstruction(int);
		void addInstruction(std::string);
		void printIdentifier();
	private:
		char identifier;
		std::vector<std::string> instructionSet;
}
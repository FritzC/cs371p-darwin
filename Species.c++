#include "Species.h"

using namespace std;

string Species::getInstruction(unsigned step) {
	if (step < instructionSet.size()) {
		return instructionSet[step];
	}
	return "";
}

void Species::addInstruction(string instruction) {
	instructionSet.push_back(instruction);
}

void Species::printIdentifier() {
	printf(identifier);
	//cout << identifier;
}
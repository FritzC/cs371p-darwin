#include "Species.h"

using namespace std;

string Species::getInstruction(int step) {
	if (step < instructionSet.size()) {
		return instructionSet[step];
	}
	return "";
}

void Species::addInstruction(string instruction) {
	instructionSet.push_back(instruction);
}

void Species::printIdentifier() {
	cout << identifier;
}
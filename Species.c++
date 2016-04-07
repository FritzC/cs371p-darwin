#include "Species.h"

using namespace std;

string Species::getInstruction(int step) {
	if (step < instructionSet.size()) {
		return instructionSet[step];
	}
	return "";
}

void addInstruction(string instruction) {
	instructionSet.push_back(instruction);
}

void printIdentifier() {
	cout << identifier;
}
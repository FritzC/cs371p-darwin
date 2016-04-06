#include "Creature.h"

using namespace std;

Creature::Creature(string id) {
	identifier = id;
}

void Creature::addInstruction(string instruction) {
	instructionSet.push_back(instruction);
}

/**
 * TODO: Implement instructions
 */
void Creature::step() {
	if (hadTurn) {
		return;
	}
	while (true) {
    	istringstream stream(instructionSet.get(currentStep));
    	string instructionType;
    	int auxInfo;
    	stream >> instructionType;
    	if (iss) {
    		iss >> auxInfo;
    	}
		if (instructionType.compare("hop")) {
			return;
		} else if (instructionType.compare("left")) {
			return;
		} else if (instructionType.compare("right")) {
			return;
		} else if (instructionType.compare("infect")) {
			return;
		} else if (instructionType.compare("if_empty")) {
			return;
		} else if (instructionType.compare("if_wall")) {
			return;
		} else if (instructionType.compare("if_random")) {
			return;
		} else if (instructionType.compare("if_enemy")) {
			return;
		} else if (instructionType.compare("go")) {
			currentStep = auxInfo;
		}
	}
	hadTurn = true;
}

void Creature::addToDarwin(Darwin& darwin, pair<int, int> location) {
	grid = darwin;
	coordinates = location;
	grid.insertCreature()
}

void Creature::infect(Creature infecter) {
	instructionSet.clear();
	instructionSet = infecter.instructionSet;
	currentStep = 0;
}
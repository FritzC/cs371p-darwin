#include "Creature.h"

using namespace std;

Creature::Creature(Species spec) {
	species = spec;
}

void Creature::step(Darwin& grid) {
	if (hadTurn) {
		return;
	}
	while (true) {
		string instruction = species.getInstruction(currentStep);
		if (instruction.compare("") == 0) {
			currentStep = 0;
			instruction = species.getInstruction(currentStep;);
		}
    	istringstream stream(instruction);
    	string instructionType;
    	int auxInfo;
    	stream >> instructionType;
    	if (iss) {
    		iss >> auxInfo;
    	}
		if (instructionType.compare("hop") == 0) {
			if(grid.getLocationType(getLocationFaced()) == Darwin::EMPTY) {
				grid.insertCreature(this&, getLocationFaced());
				grid.insertCreature(nullptr, location);
				location = getLocationFaced();
			}
			break;
		} else if (instructionType.compare("left") == 0) {
			face += 3;
			face %= 4;
			break;
		} else if (instructionType.compare("right") == 0) {
			face += 1;
			face %= 4;
			break;
		} else if (instructionType.compare("infect") == 0) {
			if (grid.getLocatioonType(getLocationFaced()) == OCCUPIED) {
				grid.getCreatureAt(getLocationFaced()).infectWith(species);
			}
			break;
		} else if (instructionType.compare("if_empty") == 0) {
			if(grid.getLocationType(getLocationFaced()) == Darwin::EMPTY) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_wall") == 0) {
			if(grid.getLocationType(getLocationFaced()) == Darwin::INVALID) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_random") == 0) {
			if(rand() % 2 == 1) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_enemy") == 0) {
			if(grid.getLocationType(getLocationFaced()) == Darwin::OCCUPIED) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("go") == 0) {
			currentStep = auxInfo;
			continue;
		}
		currentStep++;
	}
	hadTurn = true;
}

void Creature::addToDarwin(pair<int, int> coordinates) {
	location = coodinates;
}

void Creature::infectWith(Species newSpecies) {
	species = newSpecies;
	currentStep = 0;
}

void Creature::printIdentifier() {
	species.printIdentifier();
}

pair<int, int> getLocationFaced() {
	return pair<int, int>((face % 2 == 0) ? location.first + face - 1 : location.first,
							(face % 2 == 1) ? location.second + face - 2 : location.second);
}
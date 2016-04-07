#include "Creature.h"

using namespace std;

int Creature::getAction(int facedLocationType) {
	if (hadTurn) {
		return NONE;
	}
	int action = NONE;
	while (true) {
		string instruction = species.getInstruction(currentStep);
		if (instruction.compare("") == 0) {
			currentStep = 0;
			instruction = species.getInstruction(currentStep);
		}
    	istringstream stream(instruction);
    	string instructionType;
    	int auxInfo;
    	stream >> instructionType;
    	if (stream) {
    		stream >> auxInfo;
    	}
		if (instructionType.compare("hop") == 0) {
			if(facedLocationType == Darwin::EMPTY) {
				action = MOVE;
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
			if (facedLocationType == OCCUPIED) {
				action = INFECT;
			}
			break;
		} else if (instructionType.compare("if_empty") == 0) {
			if(facedLocationType == Darwin::EMPTY) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_wall") == 0) {
			if(facedLocationType == Darwin::INVALID) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_random") == 0) {
			if(rand() % 2 == 1) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_enemy") == 0) {
			if(facedLocationType == Darwin::OCCUPIED) {
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
	return action;
}

void Creature::infect(Creature* infectee) {
	infectee->species = species;
	infectee->currentStep = 0;
}

void Creature::printIdentifier() {
	species.printIdentifier();
}

pair<int, int> getLocationFaced(pair<int, int> location) {
	return pair<int, int>((face % 2 == 0) ? location.first + face - 1 : location.first,
							(face % 2 == 1) ? location.second + face - 2 : location.second);
}
#include "Creature.h"

using namespace std;

/**
 * Gets the next action of the creature
 *
 * @param facedLocationType - Type of location the creature is facing
 * @return - Type of action done by the creature
 */
int Creature::getAction(int facedLocationType) {
	int action = NONE;
	if (moved) {
		return action;
	}
	while (true) {
		string instruction = species->getInstruction(currentStep);
		//cout << endl << "\t[" << currentStep << "] " << instruction;
		if (instruction.compare("") == 0) {
			currentStep = 0;
			instruction = species->getInstruction(currentStep);
		}
    	istringstream stream(instruction);
    	string instructionType;
    	int auxInfo;
    	stream >> instructionType;
    	if (stream) {
    		stream >> auxInfo;
    	}
		if (instructionType.compare("hop") == 0) {
			if(facedLocationType == EMPTY) {
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
			if(facedLocationType == EMPTY) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_wall") == 0) {
			if(facedLocationType == INVALID) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_random") == 0) {
			if(rand() % 2 == 1) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("if_enemy") == 0) {
			if(facedLocationType == OCCUPIED && facedLocationType != ENEMY) {
				currentStep = auxInfo;
				continue;
			}
		} else if (instructionType.compare("go") == 0) {
			currentStep = auxInfo;
			continue;
		}
		currentStep++;
	}
	currentStep++;
	moved = true;
	return action;
}

/**
 * Checks if a creature is an enemy
 *
 * @return - Whether the creature is an enemy
 */
bool Creature::checkIfEnemy(Creature* other) {
	return species == other->species;
}

/**
 * Infects another creature
 *
 * @param infectee - Creature being infected
 */
void Creature::infect(Creature* infectee) {
	infectee->species = species;
	infectee->currentStep = 0;
}

/**
 * Prints the creature's species identifier
 */
void Creature::printIdentifier() {
	species->printIdentifier();
}

/**
 * Gets the location the creature is facing
 *
 * @param currentLoc - Current location of the creature
 * @return - Location the creature is facing
 */
pair<int, int> Creature::getLocationFaced(pair<int, int> currentLoc) {
	return pair<int, int>((face % 2 == 0) ? (currentLoc.first + face - 1) : currentLoc.first,
							(face % 2 == 1) ? currentLoc.second + face - 2 : currentLoc.second);
}

/**
 * Allows the creature to act again
 */
void Creature::resetTurn() {
	moved = false;
}
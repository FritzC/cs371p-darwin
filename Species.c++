#include "Species.h"

using namespace std;

/**
 * Gets the instruction at an index
 *
 * @param step - Index of instruction
 * @return - Instruction at index
 */
string Species::getInstruction(unsigned step) {
	if (step < instructionSet.size()) {
		return instructionSet[step];
	}
	return "";
}

/**
 * Adds an instruction to the instruction set
 *
 * @param instruction - Instruction added to the instruction set
 */
void Species::addInstruction(string instruction) {
	instructionSet.push_back(instruction);
}

/**
 * Prints the species' identifier
 */
void Species::printIdentifier() {
    printf("%c", identifier);
}
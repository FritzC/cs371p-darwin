#include "Darwin.h"

using namespace std;

/**
 * Creates a Darwin
 *
 * @param gridWidth - Width of the Darwin
 * @param gridHeight - Height of the Darwin
 */
Darwin::Darwin(int gridWidth, int gridHeight) {
	width = gridWidth;
	height = gridHeight;
	grid = vector<Creature*>(height * width);
	fill(grid.begin(), grid.end(), nullptr);
	turn = 0;
}

/**
 * Steps the simulation one turn forward
 */
void Darwin::step() {
	vector<Creature*> hadTurn;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (grid[y * width + x] != nullptr) {
				pair<int, int> locationFaced = grid[y * width + x]->getLocationFaced(pair<int, int>(x, y));
				int action = grid[y * width + x]->getAction(getLocationType(grid[y * width + x], locationFaced));
				if (action == Creature::MOVE) {
					grid[locationFaced.first + locationFaced.second * width] = grid[y * width + x];
					grid[y * width + x] = nullptr;
				} else if (action == Creature::INFECT) {
					grid[y * width + x]->infect(getCreatureAt(locationFaced));
				}
			}
		}
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (grid[y * width + x] != nullptr) {
				grid[y * width + x]->resetTurn();
			}
		}
	}
	turn++;
}

/**
 * Gets the type of a location
 *
 * @param creature - Creature requesting the location type
 * @param coordinates - Location being checked
 * @return - LocationType of the location
 */
int Darwin::getLocationType(Creature* creature, pair<int, int> coordinates) {
	if (coordinates.first < 0 || coordinates.first >= width
			|| coordinates.second < 0 || coordinates.second >= height) {
		return Creature::INVALID;
	} else if (grid[coordinates.first + coordinates.second * width] == nullptr) {
		return Creature::EMPTY;
	} else if (creature != nullptr 
				&& creature->checkIfEnemy(grid[coordinates.first + coordinates.second * width])) {
		return Creature::ENEMY;
	}
	return Creature::OCCUPIED;
}

/**
 * Gets the creature at a location in coordinates
 *
 * @param coordinates - Location being searched
 * @return - Creature at the location
 */
Creature* Darwin::getCreatureAt(pair<int, int> coordinates) {
	if (getLocationType(nullptr, coordinates) == Creature::INVALID) {
		throw invalid_argument("Invalid coordinates specified");
	}
	return grid[coordinates.first + coordinates.second * width];
}

/**
 * Inserts a creature into the Darwin
 *
 * @param creature - Creature being inserted
 * @param location - Location the creature is being inserted at
 */
void Darwin::insertCreature(Creature& creature, pair<int, int> location) {
	if (getLocationType(nullptr, location) != Creature::EMPTY) {
		throw invalid_argument("A Creature cannot be inserted here");
	}
	grid[location.first + location.second * width] = &creature;
}

/**
 * Prints a visualization of the Darwin
 */
void Darwin::print() {
	cout << "Turn = " << turn << "." << endl;
	cout << "  ";
	for (int x = 0; x < width; x++) {
		cout << (x % 10);
	}
	for (int idx = 0; idx < height * width; idx++) {
		if (idx % width == 0) {
			cout << endl << (idx / width % 10)  << " ";
		}
		if (grid[idx] == nullptr) {
			cout << ".";
			continue;
		}
		grid[idx]->printIdentifier();
	}
	cout << endl;
}

/**
 * Gets an iterator for the Darwin
 *
 * @return - Iterator
 */
Creature** Darwin::begin() {
	return grid.data();
}

/**
 * Gets the end of the Iterator for the Darwin
 * - darwin + size + 1
 *
 * @return - End of the Iterator
 */
Creature** Darwin::end() {
	return grid.data() + grid.size();
}

/**
 * Gets creature at an index
 *
 * @param idx - Index to get creature form
 * @return - Creature at requested index
 */
Creature* Darwin::at(int idx) {
	if (idx < 0 || idx >= width * height) {
		throw invalid_argument("Invalid index specified");
	}
	return grid[idx];
}
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
	grid = new Creature**[width];
	for (int i = 0; i < width) {
		grid[i] = new Creature*[height];
		fill(grid[i], grid[i] + height, nullptr);
	}
}

void Darwin::step() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (grid[x][y] != nullptr) {
				grid[x][y]->step(this);
			}
		}
	}
}

/**
 * Gets the type of a location
 *
 * @param coordinates - Location being checked
 * @return - LocationType of the location
 */
LocationType Darwin::getLocationType(pair<int, int> coordinates) {
	if (coordinates.first >= 0 && coordinates.first < width
			&& coordinates.second >= 0 && coordinates.second < height) {
		return INVALID;
	} else if (grid[coordinate.first][coordinate.second] == nullptr) {
		return EMPTY;
	}
	return OCCUPIED;
}

Creature* Darwin::getCreatureAt(pair<int, int> coordinates) {
	if (getLocationType(coordinates) == INVALID) {
		throw invalid_argument("Invalid coordinates specified");
	}
	return grid[coordinates.first][coordinates.second];
}

void Darwin::insertCreature(Creature* creature, pair<int, int> coordinates) {
	if (getLocationType(coordinates) != EMPTY) {
		throw invalid_argument("Invalid coordinates specified");
	}
	grid[coodinates.first][coordinates.second] = creature;
}

void Darwin::print() {
	cout << "Turn: " << turn << "." << endl;
	cout << "  ";
	for (int x = 0; x < width; x++) {
		cout << x;
	}
	cout << endl;
	for (int y = 0; y < height; y++) {
		cout << y  << " ";
		for (int x = 0; x < width; x++) {
			if (grid[x][y] == nullptr) {
				cout << ".";
				continue;
			}
			grid[x][y]->writeIdentifier();
		}
		cout << endl;
	}
}
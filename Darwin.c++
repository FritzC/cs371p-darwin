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
	for (int i = 0; i < width; i++) {
		grid[i] = new Creature*[height];
		fill(grid[i], grid[i] + height, nullptr);
	}
}

void Darwin::step() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (grid[x][y] != nullptr) {
				pair<int, int> locationFaced = grid[x][y]->getLocationFaced(pair<int, int>(x, y));
				int action = grid[x][y]->getAction(getLocationType(locationFaced));
				if (action == Creature::MOVE) {
					grid[locationFaced.first][locationFaced.second] = grid[x][y];
					grid[x][y] = nullptr;
				} else if (action == Creature::INFECT) {
					Creature* infectee = getCreatureAt(locationFaced);
					if (infectee != nullptr) {
						grid[x][y]->infect(infectee);
					}
				}
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
int Darwin::getLocationType(pair<int, int> coordinates) {
	if (coordinates.first >= 0 && coordinates.first < width
			&& coordinates.second >= 0 && coordinates.second < height) {
		return Creature::INVALID;
	} else if (grid[coordinates.first][coordinates.second] == nullptr) {
		return Creature::EMPTY;
	}
	return Creature::OCCUPIED;
}

Creature* Darwin::getCreatureAt(pair<int, int> coordinates) {
	if (getLocationType(coordinates) == Creature::INVALID) {
		throw invalid_argument("Invalid coordinates specified");
	}
	return grid[coordinates.first][coordinates.second];
}

void Darwin::insertCreature(Creature& creature, pair<int, int> location) {
	if (getLocationType(location) != Creature::EMPTY) {
		throw invalid_argument("Invalid coordinates specified");
	}
	grid[location.first][location.second] = &creature;
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
			grid[x][y]->printIdentifier();
		}
		cout << endl;
	}
}
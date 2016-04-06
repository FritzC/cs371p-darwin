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
	grid = new Creature*[height];
	for (int i = 0; i < height) {
		grid[i] = new Creature[width];
	}
}

/**
 * Checks if a coordinate is inside the grid
 *
 * @param coordinates - Coordinate being checked
 * @return - Whether the location is inside the grid
 */
bool Darwin::isValidLocation(pair<int, int> coordinates) {
	return (coordinates.first >= 0 && coordinates.first < width
			&& coordinates.second >= 0 && coordinates.second < height);
}
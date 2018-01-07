#pragma once

#include <cstdlib>
#include <time.h>
#include "Grid.h"
#include <iostream>

template<std::size_t COLS, std::size_t ROWS>
class AldousBroder : public Grid<COLS, ROWS>
{
	int unvisited = COLS * ROWS - 1;
	int X = rand() % (COLS - 1);
	int Y = rand() % (ROWS - 1);
	int neighborX, neighborY;

public:
	AldousBroder() {
		srand((unsigned)time(NULL));
		while (unvisited > 0) {
			chooseNeighbor();

			if (grid[neighborY][neighborX].noLinks()) {
				grid[Y][X].link(grid[neighborY][neighborX]);
				--unvisited;
			}

			Y = neighborY;
			X = neighborX;
		}
	}

	void chooseNeighbor() {
		int choice = rand() % 4;

		switch (choice) {
		case NORTH:
			if (isNorth(Y)) {
				neighborY = Y - 1;
				neighborX = X;
			}
			else chooseNeighbor();
			break;

		case SOUTH:
			if (isSouth(Y)) {
				neighborY = Y + 1;
				neighborX = X;
			}
			else chooseNeighbor();
			break;

		case EAST:
			if (isEast(X)) {
				neighborX = X + 1;
				neighborY = Y;
			}
			else chooseNeighbor();
			break;

		case WEST:
			if (isWest(X)) {
				neighborX = X - 1;
				neighborY = Y;
			}
			else chooseNeighbor();
			break;

		}
	}

};


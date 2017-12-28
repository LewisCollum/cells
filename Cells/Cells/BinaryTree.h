#pragma once

#include <cstdlib>
#include <time.h>
#include "Grid.h"

template<std::size_t COLS, std::size_t ROWS>
class BinaryTree : public Grid<COLS, ROWS>
{
public:
	BinaryTree() {
		srand((unsigned)time(NULL));

		for (int y = 0; y < ROWS; y++) {
			for (int x = 0; x < COLS; x++) {

				bool north;
				bool east;


				grid[y - 1][x] != nullptr ? north = true : north = false;
				grid[y][x + 1] != nullptr ? east = true : east = false;


				//grid[y][x]
				//grid[y][x].setNeighbors(true, false, true, false);

				/*if (!grid[y][x].getNeighbors().empty()) {

					int index = rand() % grid[y][x].getNeighbors().size();

					grid[y][x].link(*grid[y][x].getNeighbors()[index]);

				}
				*/

			}
		}
	}
};


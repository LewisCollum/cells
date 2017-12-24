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

		for (int y = 0; y < getRows(); y++) {
			for (int x = 0; x < getColumns(); x++) {

				grid[y][x].setNeighbors(true, false, true, false);

				if (!grid[y][x].getNeighbors().empty()) {

					int index = rand() % grid[y][x].getNeighbors().size();

					grid[y][x].link(*grid[y][x].getNeighbors()[index]);

				}

			}
		}
	}
};


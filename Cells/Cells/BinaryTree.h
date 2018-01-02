#pragma once

#include <cstdlib>
#include <time.h>
#include "Grid.h"

template<std::size_t COLS, std::size_t ROWS>
class BinaryTree : public Grid<COLS, ROWS>
{
public:
	BinaryTree();

};

template<std::size_t COLS, std::size_t ROWS>
BinaryTree<COLS, ROWS>::BinaryTree()
{
	srand((unsigned)time(NULL));

	for (int y = 0; y < ROWS; y++) {
		for (int x = 0; x < COLS; x++) {

			if (isNorth(y) && isEast(x)) {
				bool index = rand() % 2;
				index ? grid[y][x].link(grid[y - 1][x]) : grid[y][x].link(grid[y][x + 1]);
			}
			else if (isNorth(y) && !isEast(x)) {
				grid[y][x].link(grid[y - 1][x]);
			}
			else if (isEast(x) && !isNorth(y)) {
				grid[y][x].link(grid[y][x + 1]);
			}
		}
	}
}

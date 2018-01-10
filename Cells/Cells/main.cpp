/*
Implementation of Grid and Cell allows for these classes to be used for a variety of other grid-based games and algorithms
Examples include: 
Maze Algorithms (Binary Tree, Sidewinder, Recursive Backtracker, etc.)
Cellular Automata (Conway's Game of Life)

*/

#include <iostream>
#include "Cell.h"
#include "Grid.h"
#include "BinaryTree.h"
#include "AldousBroder.h"



int main() {

	std::cout << "BinaryTree: " << std::endl << BinaryTree<Cell, 6, 6>();
	std::cout << "Aldous-Broder: " << std::endl << AldousBroder<Cell, 6, 6>();
	

	//g[0][0].link(g[1][0]);
	//std::cout << g;
	/*
	int roomX = 5;
	int roomY = 5;
	int roomWidth = 5;
	int roomHeight = 5;
	
	for (int i = roomY; i < roomY + roomHeight; ++i) {
		for (int j = roomX; j < roomX + roomWidth; ++j) {

			if (j != roomX + roomWidth - 1)
				g[i][j].link(g[i][j + 1]);

			if (i != roomY + roomHeight - 1)
				g[i][j].link(g[i + 1][j]);
			
		}
	}
	*/
	
	//Grid<5, 5> alexGrid;
	//alexGrid[0][0].link(alexGrid[1][0]);
	//std::cout << alexGrid;

	//std::cout << g;


	system("pause");
	return 0;
}
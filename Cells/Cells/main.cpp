/*
Implementation of Grid and Cell allows for these classes to be used for a variety of other grid-based games and algorithms
Examples include: 
Maze Algorithms (Binary Tree, Sidewinder, Recursive Backtracker, etc.)
Cellular Automata (Conway's Game of Life)

*/

#include <iostream>
#include "Grid.h"
#include "BinaryTree.h"
#include "AldousBroder.h"

int main() {

	std::cout << "BinaryTree: " << std::endl << BinaryTree<10, 10>();
	std::cout << "Aldous-Broder: " << std::endl << AldousBroder<10, 100>();

	system("pause");
	return 0;
}
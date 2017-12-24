/*
Implementation of Grid and Cell allows for these classes to be used for a variety of other grid-based games and algorithms
Examples include: 
Maze Algorithms (Binary Tree, Sidewinder, Recursive Backtracker, etc.)
Cellular Automata (Conway's Game of Life)

*/

#include <iostream>
#include "Grid.h"
#include "BinaryTree.h"

int main() {

	Grid<20, 11> g;
	std::cout << g;

	std::cout << BinaryTree<20, 11>();

	system("pause");
	return 0;
}
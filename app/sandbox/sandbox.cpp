#include <iostream>
#include "CellGrid.hpp"
#include "BinaryTree.hpp"
#include "GridConverter.hpp"
#include "AldousBroder.hpp"

int main() {
    CellGrid<10, 10> aldousGrid;
    aldousGrid.carveWithStrategy(aldousBroder<10, 10>);
	std::cout << GridConverter::gridToString(aldousGrid);

    CellGrid<10, 10> binaryGrid;
    binaryGrid.carveWithStrategy(binaryTree<10, 10>);
	std::cout << GridConverter::gridToString(binaryGrid);
    
	return 0;
}

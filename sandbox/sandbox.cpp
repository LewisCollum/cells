#include <iostream>
#include "CellGrid.hpp"
#include "BinaryTree.hpp"
#include "GridConverter.hpp"
#include "AldousBroder.hpp"
#include "Rooms.hpp"

int main() {
    CellGrid<25, 25> aldousGrid;
    auto rooms = Rooms::generateWithinArea(25, 25, 20);
    for (auto & room : rooms) {
        room.cut(aldousGrid);
        room.fill(aldousGrid);
    }
    
    aldousBroder(aldousGrid);
	std::cout << GridConverter::gridToString(aldousGrid);

    // CellGrid<10, 10> binaryGrid;
    // binaryGrid.carveWithStrategy(binaryTree<10, 10>);
	// std::cout << GridConverter::gridToString(binaryGrid);
    
	return 0;
}

#include <iostream>
#include "CellGrid.hpp"
#include "BinaryTree.hpp"
#include "GridConverter.hpp"
#include "AldousBroder.hpp"
//#include "Room.hpp"

int main() {
    Grid<BidirectionalLinker, 10, 10> linkerGrid;
    auto neighborGrid = NeighborGrid::fromGrid(linkerGrid);
    CellGrid::Type<10, 10> cellGrid = {neighborGrid, linkerGrid};
    
    // NeighborGrid::Type<10, 10> neighborGrid;
    // NeighborGrid::setNeighbors(neighborGrid);
    // auto grid = CellGrid::fromNeighborGrid(neighborGrid);

    // CellGrid::Type<10, 10> grid;
    // CellGrid::setCellNeighbors(grid);
    // Room::Type room{x:3, y:3, width:5, height:5};
    // Room::detach(grid, room);
    // Room::fill(grid, room);

    cellGrid.carveWithStrategy(CellGrid::aldousBroder<10, 10>);
	std::cout << GridConverter::gridToString(cellGrid);

	return 0;
}

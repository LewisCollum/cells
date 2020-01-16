#ifndef TESTCELLGRID
#define TESTCELLGRID

#include <cxxtest/TestSuite.h>
#include "CellGrid.hpp"
#include "NeighborGrid.hpp"
#include "Linker.hpp"

class TestCellGrid : public CxxTest::TestSuite {
    Grid<BidirectionalLinker, 4, 4> linkerGrid;
    NeighborGrid::Type<BidirectionalLinker, 4, 4> neighborGrid = NeighborGrid::fromGrid(linkerGrid);
    CellGrid::Type<4, 4> cellGrid{neighborGrid, linkerGrid};
    
public:
    void test_forEachCell() {
        cellGrid.forEachCell([](auto neighbors, auto linker){
            if (neighbors.getEast() != nullptr)
                linker.link(*neighbors.getEast()->getHere());
        });
    }
};

#endif

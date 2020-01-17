#ifndef TESTCELLGRID
#define TESTCELLGRID

#include <cxxtest/TestSuite.h>
#include "CellGrid.hpp"

class TestCellGrid : public CxxTest::TestSuite {
    CellGrid<2, 2> grid;

public:    
    void test_topLeftHasEast() {
        Cell * expected = &grid.at(1, 0);
        Cell & topLeft = grid.at(0, 0);
        Cell * actual = topLeft.neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_bottomLeftHasNorth() {
        Cell * expected = &grid.at(0, 0);
        Cell & bottomLeft = grid.at(0, 1);
        Cell * actual = bottomLeft.neighbors.getNorth();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_topRightHasWest() {
        Cell * expected = &grid.at(0, 0);
        Cell & topRight = grid.at(1, 0);
        Cell * actual = topRight.neighbors.getWest();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_topRightHasSouth() {
        Cell * expected = &grid.at(1, 1);
        Cell & topRight = grid.at(1, 0);
        Cell * actual = topRight.neighbors.getSouth();
        
        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_topRightHasNoEast() {
        Cell * expected = nullptr;
        Cell & topRight = grid.at(1, 0);
        Cell * actual = topRight.neighbors.getEast();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_forEachCell() {
        for (auto & [neighbors, linker] : grid)
            if (neighbors.getEast() != nullptr)
                linker.link(neighbors.getEast()->linker);
    }
};

#endif

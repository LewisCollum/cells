#ifndef TESTCELLGRID
#define TESTCELLGRID

#include <cxxtest/TestSuite.h>
#include "cell/Grid.hpp"

class TestGrid : public CxxTest::TestSuite {
    cell::Grid<2, 2> grid;

public:    
    void test_topLeftHasEast() {
        cell::Cell * expected = &grid.at(1, 0);
        cell::Cell & topLeft = grid.at(0, 0);
        cell::Cell * actual = topLeft.east.get();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_bottomLeftHasNorth() {
        cell::Cell * expected = &grid.at(0, 0);
        cell::Cell & bottomLeft = grid.at(0, 1);
        cell::Cell * actual = bottomLeft.north.get();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_topRightHasWest() {
        cell::Cell * expected = &grid.at(0, 0);
        cell::Cell & topRight = grid.at(1, 0);
        cell::Cell * actual = topRight.west.get();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_topRightHasSouth() {
        cell::Cell * expected = &grid.at(1, 1);
        cell::Cell & topRight = grid.at(1, 0);
        cell::Cell * actual = topRight.south.get();
        
        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_topRightHasNoEast() {
        cell::Cell * expected = nullptr;
        cell::Cell & topRight = grid.at(1, 0);
        cell::Cell * actual = topRight.east.get();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_forEachCell() {
        for (auto & cell : grid)
            if (cell.east.get() != nullptr)
                cell.link(*cell.east.get());
    }
};

#endif

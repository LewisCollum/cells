#ifndef TESTCELLGRID
#define TESTCELLGRID

#include <cxxtest/TestSuite.h>
#include "CellGrid.hpp"
#include "Cell.hpp"
#include "Linker.hpp"
#include "Neighbors.hpp"

class TestCellGrid: public CxxTest::TestSuite {
    CellGrid::Type<2, 2> grid;

public:

    void test_topLeftCellLinkToEast() {
        CellGrid::setCellNeighbors(grid);
        Cell & topLeftCell = grid.at(0, 0);
        Cell * east = topLeftCell.neighbors.getEast();

        topLeftCell.linker.link(east->linker);
    }

    void test_bottomLeftCellHasNorth() {
        CellGrid::setCellNeighbors(grid);
        
        Cell const * expected = &grid.at(0, 0);
        Cell & topRightCell = grid.at(0, 1);
        Cell const * actual = topRightCell.neighbors.getNorth();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_topRightCellHasWest() {
        CellGrid::setCellNeighbors(grid);
        
        Cell const * expected = &grid.at(0, 0);
        Cell & topRightCell = grid.at(1, 0);
        Cell const * actual = topRightCell.neighbors.getWest();
        
        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_topRightCellHasSouth() {
        CellGrid::setCellNeighbors(grid);
        
        Cell const * expected = &grid.at(1, 1);
        Cell & topRightCell = grid.at(1, 0);
        Cell const * actual = topRightCell.neighbors.getSouth();
        
        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_topRightCellHasNoEast() {
        CellGrid::setCellNeighbors(grid);
        
        Cell const * expected = nullptr;
        Cell & topRightCell = grid.at(1, 0);
        Cell const * actual = topRightCell.neighbors.getEast();
        
        TS_ASSERT_EQUALS(expected, actual);
    }    

    void test_topLeftCellHasEast() {
        CellGrid::setCellNeighbors(grid);
        
        Cell const * expected = &grid.at(1, 0);
        Cell & topLeftCell = grid.at(0, 0);
        Cell const * actual = topLeftCell.neighbors.getEast();
        
        TS_ASSERT_EQUALS(expected, actual);
    }

    void tearDown() {
        grid = CellGrid::Type<2, 2>();
    }
};

#endif

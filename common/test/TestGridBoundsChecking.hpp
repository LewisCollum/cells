#ifndef TESTGRIDBOUNDSCHECKING
#define TESTGRIDBOUNDSCHECKING

#include <cxxtest/TestSuite.h>
#include "Grid.hpp"

class TestGridBoundsChecking: public CxxTest::TestSuite {
    struct MockElement{};    
    Grid<MockElement, 2, 1> grid;
    
public:
    void test_size() {
        size_t expected = 2;
        size_t actual = grid.size();

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_outOfPositiveColumnBounds_isWithinBoundsReturnsFalse() {
        bool expected = false;
        bool actual = grid.isWithinBounds(2, 0);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_outOfNegativeColumnBounds_isWithinBoundsReturnsFalse() {
        bool expected = false;
        bool actual = grid.isWithinBounds(-1, 0);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_outOfPositiveRowBounds_isWithinBoundsReturnsFalse() {
        bool expected = false;
        bool actual = grid.isWithinBounds(0, 1);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_outOfNegativeRowBounds_isWithinBoundsReturnsFalse() {
        bool expected = false;
        bool actual = grid.isWithinBounds(0, -1);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_inBounds_isWithinBoundsReturnsTrue() {
        bool expected = true;
        bool actual = grid.isWithinBounds(1, 0);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void tearDown() {
        grid = Grid<MockElement, 2, 1>{};
    }
};

#endif

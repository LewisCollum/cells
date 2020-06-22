#ifndef TESTNEIGHBORS
#define TESTNEIGHBORS

#include <cxxtest/TestSuite.h>
#include "cell/Neighbors.hpp"

class TestNeighbors: public CxxTest::TestSuite {
    struct MockNeighbor{};
    cell::Neighbors<MockNeighbor> neighbors;
    MockNeighbor expectedNeighbor;
    
public:
    void test_unlinkEastWithoutSettingEast_nothingChanges() {
        neighbors.unlinkEast();

        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_unlinkEastAfterSettingEast_eastIsNull() {
        neighbors.setEast(expectedNeighbor);
        neighbors.unlinkEast();

        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_doNotSetEast_eastIsNull() {
        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = neighbors.getEast();
        
        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_setEast_getEast() {
        neighbors.setEast(expectedNeighbor);

        MockNeighbor * actual = neighbors.getEast();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void test_setWest_getWest() {
        neighbors.setWest(expectedNeighbor);

        MockNeighbor * actual = neighbors.getWest();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void test_setNorth_getNorth() {
        neighbors.setNorth(expectedNeighbor);

        MockNeighbor * actual = neighbors.getNorth();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void test_setSouth_getSouth() {
        neighbors.setSouth(expectedNeighbor);

        MockNeighbor * actual = neighbors.getSouth();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void tearDown() {
        neighbors = cell::Neighbors<MockNeighbor>{};
    }
};

#endif

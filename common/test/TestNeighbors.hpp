#ifndef TESTNEIGHBORS
#define TESTNEIGHBORS

#include <cxxtest/TestSuite.h>
#include "Neighbors.hpp"

class TestNeighbors: public CxxTest::TestSuite {
    struct MockNeighbor{};
    Neighbors<MockNeighbor> neighbors;
    decltype(neighbors) expectedNeighbor;
    
public:
    void test_unlinkEastWithoutSettingEast_nothingChanges() {
        neighbors.unlinkEast();

        decltype(neighbors)::pointer expected = nullptr;
        decltype(neighbors)::pointer actual = neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_unlinkEastAfterSettingEast_eastIsNull() {
        neighbors.setEast(expectedNeighbor);
        neighbors.unlinkEast();

        decltype(neighbors)::pointer expected = nullptr;
        decltype(neighbors)::pointer actual = neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_doNotSetEast_eastIsNull() {
        decltype(neighbors)::pointer expected = nullptr;
        decltype(neighbors)::pointer actual = neighbors.getEast();
        
        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_setEast_getEast() {
        neighbors.setEast(expectedNeighbor);

        decltype(neighbors)::pointer actual = neighbors.getEast();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void test_setWest_getWest() {
        neighbors.setWest(expectedNeighbor);

        decltype(neighbors)::pointer actual = neighbors.getWest();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void test_setNorth_getNorth() {
        neighbors.setNorth(expectedNeighbor);

        decltype(neighbors)::pointer actual = neighbors.getNorth();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void test_setSouth_getSouth() {
        neighbors.setSouth(expectedNeighbor);

        decltype(neighbors)::pointer actual = neighbors.getSouth();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actual);
    }

    void tearDown() {
        neighbors = Neighbors<MockNeighbor>{};
    }
};

#endif

#ifndef TESTNEIGHBORSELECTOR
#define TESTNEIGHBORSELECTOR

#include <cxxtest/TestSuite.h>
#include "NeighborSelector.hpp"
#include "Neighbors.hpp"

struct MockNeighbor{};

class TestNeighborSelector: public CxxTest::TestSuite {
    Neighbors<MockNeighbor> neighbors;
    
public:
    void test_allEmpty_returnNullSelection() {
        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = NeighborSelector::select(neighbors);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_allSelectionsNull_returnNull() {
        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = NeighborSelector::select({
                neighbors.getEast(),
                neighbors.getNorth()});

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_selectFromOneValidOneNullDirections_onlyValidSelected() {
        MockNeighbor east, west;
        neighbors.setEast(east);
        neighbors.setWest(west);

        auto expected = &east;
        auto actual = NeighborSelector::select({
                neighbors.getEast(),
                neighbors.getNorth()});

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_fromAll_oneNeighborSelectedFromAll() {
        MockNeighbor neighborA, neighborB;
        neighbors.setEast(neighborA);
        neighbors.setWest(neighborB);
        
        auto choice = NeighborSelector::select(neighbors);

        TS_ASSERT((choice == &neighborA) xor (choice == &neighborB));
    }

    void tearDown() {
        neighbors = Neighbors<MockNeighbor>{};
    }
};

#endif

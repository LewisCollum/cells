#ifndef TESTRANDOMSELECTORONNEIGHBORS
#define TESTRANDOMSELECTORONNEIGHBORS

#include <cxxtest/TestSuite.h>
#include "Neighbors.hpp"
#include "RandomSelector.hpp"

class TestRandomSelectorOnNeighbors: public CxxTest::TestSuite {
    struct MockNeighbor{};
    Neighbors<MockNeighbor> neighbors;
    
public:
    void test_allEmpty_returnNullSelection() {
        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = RandomSelector::select(neighbors);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_allSelectionsNull_returnNull() {
        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = RandomSelector::select({
                neighbors.getEast(),
                neighbors.getNorth()});

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_selectFromOneValidOneNullDirections_onlyValidSelected() {
        MockNeighbor east, west;
        neighbors.setEast(east);
        neighbors.setWest(west);

        auto expected = &east;
        auto actual = RandomSelector::select({
                neighbors.getEast(),
                neighbors.getNorth()});

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_fromAll_oneNeighborSelectedFromAll() {
        MockNeighbor neighborA, neighborB;
        neighbors.setEast(neighborA);
        neighbors.setWest(neighborB);
        
        MockNeighbor * choice = RandomSelector::select(neighbors);

        TS_ASSERT((choice == &neighborA) xor (choice == &neighborB));
    }

    void tearDown() {
        neighbors = Neighbors<MockNeighbor>{};
    }
};

#endif

#include <cxxtest/TestSuite.h>
#include "Neighbors.hpp"

class TestNeighbors: public CxxTest::TestSuite {
    struct MockNeighbor {};
    Neighbors<MockNeighbor> neighbors;

public:
    void test_setEast_getEast() {
        MockNeighbor expectedNeighbor;
        MockNeighbor const * const expectedNeighborAddress = &expectedNeighbor;
        
        neighbors.setEast(&expectedNeighbor);
        MockNeighbor const * const actualNeighborAddress = neighbors.getEast();
        
        TS_ASSERT_EQUALS(expectedNeighborAddress, actualNeighborAddress);
    }
};

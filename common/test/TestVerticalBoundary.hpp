#ifndef TESTVERTICALBOUNDARYLINE
#define TESTVERTICALBOUNDARYLINE

#include <cxxtest/TestSuite.h>
#include "BoundaryLine.hpp"
#include "Coordinates.hpp"

class TestVerticalBoundaryLine : public CxxTest::TestSuite {
    Coordinates const boundaryOrigin = {1,2};
    int const boundaryLength = 10;
    VerticalBoundaryLine boundary{{origin: boundaryOrigin, magnitude: boundaryLength}};

public:
    void test_stepCoordinates_allFirstColumnEqualsOriginX() {
        auto expected = boundaryOrigin.x;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary)
            if (lateralCoordinates.first.x != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_allSecondColumnEqualsOriginXPlusOne() {
        auto expected = boundaryOrigin.x+1;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary)
            if (lateralCoordinates.second.x != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_columnsHaveSameY() {
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary) 
            if (lateralCoordinates.first.y != lateralCoordinates.second.y)
                isExpected = false;

        TS_ASSERT(isExpected);
    }
};

#endif

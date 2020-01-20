#ifndef TESTVERTICALBOUNDARYLINE
#define TESTVERTICALBOUNDARYLINE

#include <cxxtest/TestSuite.h>
#include "BoundaryLine.hpp"
#include "Coordinates.hpp"

class TestVerticalBoundaryLine : public CxxTest::TestSuite {
    static constexpr PointMagnitude line{origin:{x:1,y:2}, magnitude:10};
    VerticalBoundaryLine<line> boundary{};

public:
    void test_stepCoordinates_allFirstColumnEqualsOriginX() {
        auto expected = line.origin.x;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary)
            if (lateralCoordinates.first.x != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_allSecondColumnEqualsOriginXPlusOne() {
        auto expected = line.origin.x+1;
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

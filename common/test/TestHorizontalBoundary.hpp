#ifndef TESTHORIZONTALBOUNDARYLINE
#define TESTHORIZONTALBOUNDARYLINE

#include <cxxtest/TestSuite.h>
#include "BoundaryLine.hpp"
#include "Coordinates.hpp"
#include "PointMagnitude.hpp"

class TestHorizontalBoundaryLine : public CxxTest::TestSuite {
    static constexpr PointMagnitude line{origin:{x:1,y:2}, magnitude:10};
    HorizontalBoundaryLine<line> boundaryLine{};
    
public:
    void test_stepCoordinates_allFirstRowEqualsOriginY() {
        auto expected = line.origin.y;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundaryLine)
            if (lateralCoordinates.first.y != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_allSecondRowEqualsOriginYPlusOne() {
        auto expected = line.origin.y+1;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundaryLine)
            if (lateralCoordinates.second.y != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_columnsHaveSameX() {
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundaryLine) 
            if (lateralCoordinates.first.x != lateralCoordinates.second.x)
                isExpected = false;

        TS_ASSERT(isExpected);
    }
};

#endif

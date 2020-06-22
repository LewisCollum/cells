#ifndef RECTANGLE_TESTHORIZONTALBOUNDARYLINE
#define RECTANGLE_TESTHORIZONTALBOUNDARYLINE

#include <cxxtest/TestSuite.h>
#include "rectangle/BoundaryLine.hpp"
#include "rectangle/Coordinates.hpp"

class TestHorizontalBoundaryLine : public CxxTest::TestSuite {
    rectangle::Coordinates const origin{x:1,y:2};
    rectangle::HorizontalBoundaryLine const boundaryLine{origin, 10};
    
public:
    void test_stepCoordinates_allFirstRowEqualsOriginY() {
        auto expected = origin.y;
        bool isExpected = true;
        
        for (auto const & lateralCoordinates: boundaryLine)
            if (lateralCoordinates.first.y != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_allSecondRowEqualsOriginYPlusOne() {
        auto expected = origin.y+1;
        bool isExpected = true;
        
        for (auto const & lateralCoordinates: boundaryLine)
            if (lateralCoordinates.second.y != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_columnsHaveSameX() {
        bool isExpected = true;
        
        for (auto const & lateralCoordinates: boundaryLine) 
            if (lateralCoordinates.first.x != lateralCoordinates.second.x)
                isExpected = false;

        TS_ASSERT(isExpected);
    }
};

#endif

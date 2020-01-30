#ifndef RECTANGLE_TESTHORIZONTALBOUNDARYLINE
#define RECTANGLE_TESTHORIZONTALBOUNDARYLINE

#include <cxxtest/TestSuite.h>
#include "BoundaryLine.hpp"
#include "Coordinates.hpp"

class TestHorizontalBoundaryLine : public CxxTest::TestSuite {
    static constexpr rectangle::Coordinates origin{x:1,y:2};
    static constexpr rectangle::HorizontalBoundaryLine<10> boundaryLine{origin};
    
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

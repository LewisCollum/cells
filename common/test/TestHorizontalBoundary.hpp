#ifndef TESTHORIZONTALBOUNDARY
#define TESTHORIZONTALBOUNDARY

#include "Boundary.hpp"
#include "Coordinates.hpp"

class TestHorizontalBoundary : public CxxTest::TestSuite {
    Coordinates const boundaryOrigin = {1,2};
    int const boundaryLength = 10;
    HorizontalBoundary boundary{boundaryOrigin, boundaryLength};

public:
    void test_stepCoordinateSize_isLengthOfBoundary() {
        auto expected = boundaryLength;
        auto actual = boundary.size();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_stepCoordinates_allFirstRowEqualsOriginY() {
        auto expected = boundaryOrigin.y;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary)
            if (lateralCoordinates.first.y != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_allSecondRowEqualsOriginYPlusOne() {
        auto expected = boundaryOrigin.y+1;
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary)
            if (lateralCoordinates.second.y != expected)
                isExpected = false;

        TS_ASSERT(isExpected);
    }

    void test_stepCoordinates_columnsHaveSameX() {
        bool isExpected = true;
        
        for (auto lateralCoordinates: boundary) 
            if (lateralCoordinates.first.x != lateralCoordinates.second.x)
                isExpected = false;

        TS_ASSERT(isExpected);
    }
};

#endif

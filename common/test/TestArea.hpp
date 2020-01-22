#ifndef TESTAREA
#define TESTAREA

#include <cxxtest/TestSuite.h>
#include <tuple>
#include "RectangularLimits.hpp"
#include "BoundaryLine.hpp"

template <RectangularLimits limits>
class Area {
    static constexpr int width() {
        return limits.x.second - limits.x.first + 1;
    }

    static constexpr int height() {
        return limits.y.second - limits.y.first + 1;
    }
        
    VerticalBoundaryLine<height()> westBoundaryLine;
    VerticalBoundaryLine<height()> eastBoundaryLine;
    HorizontalBoundaryLine<width()> northBoundaryLine;
    HorizontalBoundaryLine<width()>  southBoundaryLine;
    
public:
    constexpr Area() :
        westBoundaryLine{{x: limits.x.first-1, y: limits.y.first}},
        eastBoundaryLine{{x: limits.x.second-1, y: limits.y.first}},
        northBoundaryLine{{x: limits.x.first, y: limits.y.first-1}},
        southBoundaryLine{{x: limits.x.second, y: limits.y.second-1}} {}   
};

class TestArea : public CxxTest::TestSuite {
    static constexpr RectangularLimits areaLimits{x: {0,2}, y: {0,3}};
    Area<areaLimits> area{};

public:
    // void test_boundaryLinesWithinMinimumLimits_noBoundaryLines() {
    //     RectangularLimits coordinateLimits = areaLimits;
    //     auto boundaryLines = area.boundaryLinesWithinLimits(coordinateLimits);

    //     auto expected = 0;
    //     auto actual = std::tuple_size<decltype(boundaryLines)>::value;

    //     TS_ASSERT_EQUALS(expected, actual);
    // }

    // void test_boundaryLinesWithinExtendedWestLimits_singleVerticalBoundaryLine() {
    //     RectangularLimits coordinateLimits = areaLimits;
    //     auto boundaryLines = area.boundaryLinesWithinLimits(coordinateLimits);

    //     auto expected = 1;
    //     auto actual = std::tuple_size<decltype(boundaryLines)>::value;

    //     TS_ASSERT_EQUALS(expected, actual);
    // }    
};

#endif

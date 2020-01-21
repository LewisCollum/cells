#ifndef TESTAREA
#define TESTAREA

#include <cxxtest/TestSuite.h>
#include <tuple>
#include "RectangularLimits.hpp"
#include "BoundaryLine.hpp"

template <RectangularLimits limits>
class Area {
    constexpr int width() {
        return limits.x.second - limits.x.first + 1;
    }

    constexpr int height() {
        return limits.y.second - limits.y.first + 1;
    }
        
    VerticalBoundaryLine<limits.y.second - limits.y.first + 1> westBoundaryLine{{limits.x.first-1, limits.y.first}};
    // VerticalBoundaryLine const eastBoundaryLine;
    // HorizontalBoundaryLine const northBoundaryLine;
    // HorizontalBoundaryLine const southBoundaryLine;
    
public:

    // constexpr Area(RectangularLimits limits) :
    //     limits{limits},
    //     westBoundaryLine{makeWestBoundaryLine()},
    //     eastBoundaryLine{makeEastBoundaryLine()},
    //     northBoundaryLine{makeNorthBoundaryLine()},
    //     southBoundaryLine{makeSouthBoundaryLine()} {}
    

    auto boundaryLinesWithinLimits(RectangularLimits otherLimits) {
        std::tuple boundaryLines{};
        // if(bool isWest = this->limits.x.first > limits.x.first)            
        //     std::tuple_cat(boundaryLines, westBoundaryLine);

        return boundaryLines;
    }
private:
    // PointMagnitude makeWestLine() {
    //     return {
    //       origin: {x:limits.x.first-1, y:limits.y.first},
    //       magnitude: 1 //height()
    //     };
    // }


    // constexpr VerticalBoundaryLine makeEastBoundaryLine() const {
    //     constexpr PointMagnitude eastLine{
    //       origin: {x: limits.x.second-1, y: limits.y.first},
    //       magnitude: height()
    //     };

    //     return VerticalBoundaryLine{eastLine};
    // }

    // constexpr HorizontalBoundaryLine makeNorthBoundaryLine() const {
    //     constexpr PointMagnitude northLine{
    //       origin: {x: limits.x.first, y: limits.y.first-1},
    //       magnitude: width()
    //     };

    //     return HorizontalBoundaryLine{northLine};
    // }

    // constexpr HorizontalBoundaryLine makeSouthBoundaryLine() const {
    //     constexpr PointMagnitude southLine{
    //       origin: {x: limits.x.second, y: limits.y.second-1},
    //       magnitude: width()
    //     };

    //     return HorizontalBoundaryLine{southLine};
    // }    
};

class TestArea : public CxxTest::TestSuite {
    constexpr static RectangularLimits const areaLimits{x: {0,2}, y: {0,3}};
    constexpr static Area<areaLimits> area{};

public:
    void test_() {}
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

    //     auto expected = 0;
    //     auto actual = std::tuple_size<decltype(boundaryLines)>::value;

    //     TS_ASSERT_EQUALS(expected, actual);
    // }    
};

#endif

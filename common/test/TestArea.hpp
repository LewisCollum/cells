#ifndef TESTAREA
#define TESTAREA

#include <cxxtest/TestSuite.h>
#include <tuple>
#include "RectangularLimits.hpp"
#include "BoundaryLine.hpp"

class Area {
    RectangularLimits limits;

    VerticalBoundaryLine const westBoundaryLine;
    VerticalBoundaryLine const eastBoundaryLine;
    HorizontalBoundaryLine const northBoundaryLine;
    HorizontalBoundaryLine const southBoundaryLine;
    
public:
    constexpr Area(RectangularLimits limits) :
        limits{limits},
        westBoundaryLine{makeWestBoundaryLine()},
        eastBoundaryLine{makeEastBoundaryLine()},
        northBoundaryLine{makeNorthBoundaryLine()},
        southBoundaryLine{makeSouthBoundaryLine()} {}
    
    constexpr int width() const {
        return limits.x.second - limits.x.first + 1;
    }

    constexpr int height() const {
        return limits.y.second - limits.y.first + 1;
    }
    
    auto boundaryLinesWithinLimits(RectangularLimits limits) {
        std::tuple boundaryLines{};
        // if(bool isWest = this->limits.x.first > limits.x.first)            
        //     std::tuple_cat(boundaryLines, westBoundaryLine);

        return boundaryLines;
    }
private:
    constexpr VerticalBoundaryLine makeWestBoundaryLine() {
        PointMagnitude westLine{
          origin: {x: limits.x.first-1, y: limits.y.first},
          magnitude: height()
        };

        return VerticalBoundaryLine{westLine};
    }

    constexpr VerticalBoundaryLine makeEastBoundaryLine() {
        PointMagnitude eastLine{
          origin: {x: limits.x.second-1, y: limits.y.first},
          magnitude: height()
        };

        return VerticalBoundaryLine{eastLine};
    }

    constexpr HorizontalBoundaryLine makeNorthBoundaryLine() {
        PointMagnitude northLine{
          origin: {x: limits.x.first, y: limits.y.first-1},
          magnitude: width()
        };

        return VerticalBoundaryLine{northLine};
    }

    constexpr HorizontalBoundaryLine makeSouthBoundaryLine() {
        PointMagnitude southLine{
          origin: {x: limits.x.second, y: limits.y.second-1},
          magnitude: width()
        };

        return VerticalBoundaryLine{northLine};
    }    
};

class TestArea : public CxxTest::TestSuite {
    RectangularLimits areaLimits{x: {0,2}, y: {0,3}};
    Area area{areaLimits};

public:
    void test_boundaryLinesWithinMinimumLimits_noBoundaryLines() {
        RectangularLimits coordinateLimits = areaLimits;
        auto boundaryLines = area.boundaryLinesWithinLimits(coordinateLimits);

        auto expected = 0;
        auto actual = std::tuple_size<decltype(boundaryLines)>::value;

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_boundaryLinesWithinExtendedWestLimits_singleVerticalBoundaryLine() {
        RectangularLimits coordinateLimits = areaLimits;
        auto boundaryLines = area.boundaryLinesWithinLimits(coordinateLimits);

        auto expected = 0;
        auto actual = std::tuple_size<decltype(boundaryLines)>::value;

        TS_ASSERT_EQUALS(expected, actual);
    }    
};

#endif

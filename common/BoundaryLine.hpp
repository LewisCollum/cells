#ifndef BOUNDARYLINE
#define BOUNDARYLINE

#include <array>
#include "Coordinates.hpp"
#include "PointMagnitude.hpp"

template <PointMagnitude line, bool isHorizontal, bool isVertical = !isHorizontal>
class BoundaryLine {
    using LateralCoordinates = std::pair<Coordinates, Coordinates>;
    std::array<LateralCoordinates, line.magnitude> boundaryLine;

public:
    constexpr BoundaryLine() : boundaryLine{} {
        makeBoundaryLine();
    }

    auto const begin() { return boundaryLine.begin(); }
    auto const end() { return boundaryLine.end(); }

private:
    constexpr void makeBoundaryLine() requires isHorizontal {
        for (int i = 0; i < line.magnitude; ++i) {
            LateralCoordinates lateralCoordinates;
            lateralCoordinates.first = {line.origin.x + i, line.origin.y};
            lateralCoordinates.second = {line.origin.x + i, line.origin.y+1};
            boundaryLine[i] = lateralCoordinates;
        }
    }

    constexpr void makeBoundaryLine() requires isVertical {
       for (int i = 0; i < line.magnitude; ++i) {
           LateralCoordinates lateralCoordinates;
           lateralCoordinates.first = {line.origin.x, line.origin.y + i};
           lateralCoordinates.second = {line.origin.x+1, line.origin.y + i};
           boundaryLine[i] = lateralCoordinates;
       }
   }    
};

template <PointMagnitude line>
using HorizontalBoundaryLine = BoundaryLine<line, true>;

template <PointMagnitude line>
using VerticalBoundaryLine = BoundaryLine<line, false>;    

#endif

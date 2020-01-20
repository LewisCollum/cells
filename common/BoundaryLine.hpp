#ifndef BOUNDARYLINE
#define BOUNDARYLINE

#include "Coordinates.hpp"
#include "PointMagnitude.hpp"

template <bool isHorizontal, bool isVertical = !isHorizontal>
class BoundaryLine {
    using LateralCoordinates = std::pair<Coordinates, Coordinates>;
    std::vector<LateralCoordinates> boundaryLine;
    PointMagnitude line;
    
public:
    constexpr BoundaryLine(PointMagnitude line) :
        line{line},
        boundaryLine{makeBoundaryLine()} {}

    auto size() { return boundaryLine.size(); }
    auto const operator[](size_t index) { return boundaryLine[index]; }
    auto const begin() { return boundaryLine.begin(); }
    auto const end() { return boundaryLine.end(); }

private:
    constexpr std::vector<LateralCoordinates> makeBoundaryLine() requires isHorizontal {
        for (int i = 0; i < line.magnitude; ++i) {
            LateralCoordinates lateralCoordinates;
            lateralCoordinates.first = {line.origin.x + i, line.origin.y};
            lateralCoordinates.second = {line.origin.x + i, line.origin.y+1};
            boundaryLine.emplace_back(lateralCoordinates);
        }
    }

   constexpr std::vector<LateralCoordinates> makeBoundaryLine() requires isVertical {
        for (int i = 0; i < line.magnitude; ++i) {
            LateralCoordinates lateralCoordinates;
            lateralCoordinates.first = {line.origin.x, line.origin.y + i};
            lateralCoordinates.second = {line.origin.x+1, line.origin.y + i};
            boundaryLine.emplace_back(lateralCoordinates);
        }
    }    
};

using HorizontalBoundaryLine = BoundaryLine<true>;
using VerticalBoundaryLine = BoundaryLine<false>;

#endif

#ifndef BOUNDARYLINE
#define BOUNDARYLINE

#include <array>
#include "Coordinates.hpp"

template <int length, bool isHorizontal, bool isVertical = !isHorizontal>
class BoundaryLine {
    using LateralCoordinates = std::pair<Coordinates, Coordinates>;
    Coordinates origin;
    std::array<LateralCoordinates, length> boundaryLine;

public:
    constexpr BoundaryLine(Coordinates origin) : origin{origin}, boundaryLine{} {
        makeBoundaryLine();
    }

    auto const begin() const { return boundaryLine.begin(); }
    auto const end() const { return boundaryLine.end(); }

private:
    constexpr void makeBoundaryLine() requires isHorizontal {
        for (int i = 0; i < length; ++i) {
            boundaryLine[i].first = {origin.x + i, origin.y};
            boundaryLine[i].second = {origin.x + i, origin.y+1};
        }
    }
    
    constexpr void makeBoundaryLine() requires isVertical {
        for (int i = 0; i < length; ++i) {
            boundaryLine[i].first = {origin.x, origin.y + i};
            boundaryLine[i].second = {origin.x+1, origin.y + i};
        }
    }
};

template <int length>
using HorizontalBoundaryLine = BoundaryLine<length, true>;

template <int length>
using VerticalBoundaryLine = BoundaryLine<length, false>;    

#endif

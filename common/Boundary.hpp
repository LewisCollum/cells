#ifndef BOUNDARY
#define BOUNDARY

#include "Coordinates.hpp"

template <bool isHorizontal, bool isVertical = !isHorizontal>
class Boundary {
    using LateralCoordinates = std::pair<Coordinates, Coordinates>;
    Coordinates const origin;
    int const length;
    std::vector<LateralCoordinates> boundary;
    
public:
    constexpr Boundary(Coordinates origin, int length) : origin{origin}, length{length} {
        makeBoundary();
    }

    auto size() { return boundary.size(); }
    auto operator[](size_t index) { return boundary[index]; }
    auto begin() { return boundary.begin(); }
    auto end() { return boundary.end(); }

private:
    auto makeBoundary() requires isHorizontal {
        for (int i = 0; i < length; ++i) {
            LateralCoordinates lateralCoordinates;
            lateralCoordinates.first = {origin.x + i, origin.y};
            lateralCoordinates.second = {origin.x + i, origin.y+1};
            boundary.emplace_back(lateralCoordinates);
        }
        return boundary;
    }

    auto makeBoundary() requires isVertical {
        for (int i = 0; i < length; ++i) {
            LateralCoordinates lateralCoordinates;
            lateralCoordinates.first = {origin.x, origin.y + i};
            lateralCoordinates.second = {origin.x+1, origin.y + i};
            boundary.emplace_back(lateralCoordinates);
        }
        return boundary;
    }    
};

using HorizontalBoundary = Boundary<true>;
using VerticalBoundary = Boundary<false>;

#endif

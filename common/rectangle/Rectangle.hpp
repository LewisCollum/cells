#ifndef RECTANGLE
#define RECTANGLE

#include <tuple>
#include "Limits.hpp"
#include "Coordinates.hpp"

class Rectangle {
    rectangle::Limits limits;
    rectangle::Coordinates origin;
    
    constexpr Rectangle(rectangle::Limits limits) :
        limits{limits},
        origin{{limits.x.first, limits.y.first}} {}

    constexpr bool isOverlapping(Rectangle const & other) const {
        return isXOverlapping(other) and isYOverlapping(other);
    }

    constexpr bool isXOverlapping(Rectangle const & other) const {
        return originXDistanceTo(other) >= 0 ?
            limits.width() >= originXDistanceTo(other) :
            other.limits.width() >= abs(originXDistanceTo(other));
    }

    constexpr bool isYOverlapping(Rectangle const & other) const {
        return originYDistanceTo(other) >= 0 ?
            limits.height() >= originYDistanceTo(other) :
            other.limits.height() >= abs(originYDistanceTo(other));
    }

    constexpr std::tuple<int, int> originDistanceTo(Rectangle const & other) const {
        return {originXDistanceTo(other), originYDistanceTo(other)};
    }

    constexpr int originXDistanceTo(Rectangle const & other) const {
        return origin.x - other.origin.x;
    }

    constexpr int originYDistanceTo(Rectangle const & other) const {
        return origin.y - other.origin.y;
    }    
};

#endif

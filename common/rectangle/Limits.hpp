#ifndef RECTANGLE_LIMITS
#define RECTANGLE_LIMITS

#include <utility>
#include "rectangle/Coordinates.hpp"

namespace rectangle {
    struct Limits {
        std::pair<int, int> x;
        std::pair<int, int> y;
        
        constexpr int width() const {
            return x.second - x.first + 1;
        }

        constexpr int height() const {
            return y.second - y.first + 1;
        }

        constexpr rectangle::Coordinates origin() const {
            return {x: x.first, y: y.first};
        }        
    };
}

#endif

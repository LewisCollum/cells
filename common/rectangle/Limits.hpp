#ifndef RECTANGLE_LIMITS
#define RECTANGLE_LIMITS

#include <utility>
#include "rectangle/Coordinates.hpp"

namespace rectangle {
    struct Limits {
        std::pair<int, int> x;
        std::pair<int, int> y;

        constexpr Limits(std::pair<int, int> x, std::pair<int, int> y) : x{x}, y{y} {}
        
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

    // struct Limits : Grid<Coordinates, 2, 2> {
    //     std::pair<int, int> x;
    //     std::pair<int, int> y;

    //     constexpr Limits(std::pair<int, int> x, std::pair<int, int> y) : x{x}, y{y} {
    //         at(0, 0) = {x.first, y.first};
    //         at(1, 0) = {x.second, y.first};
    //         at(1, 1) = {x.second, y.second};
    //         at(0, 1) = {x.first, y.second};
    //     }
        
    //     constexpr int width() const {
    //         return x.second - x.first + 1;
    //     }

    //     constexpr int height() const {
    //         return y.second - y.first + 1;
    //     }
        
    // };
    
    // using Limits = Grid<int, 2, 2>;
}

#endif

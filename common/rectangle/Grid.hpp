#ifndef RECTANGLE_GRID
#define RECTANGLE_GRID

#include <array>
#include "rectangle/Coordinates.hpp"

namespace rectangle {
    template<typename Element, size_t columns, size_t rows>
    struct Grid {
        using value_type = Element;
    
    private:
        std::array<value_type, columns*rows> grid;
    
    public:
        constexpr bool isWithinBounds(size_t x, size_t y) {
            return x < columns and x >= 0 and y < rows and y >= 0;
        }

        constexpr bool isWithinBounds(rectangle::Coordinates coordinates) {
            return isWithinBounds(coordinates.x, coordinates.y);
        }

        constexpr Element & at(size_t x, size_t y) {
            return grid[y * columns + x];
        }

        constexpr Element & at(size_t x, size_t y) const {
            return grid[y * columns + x];
        }
        
        constexpr Element & at(rectangle::Coordinates coordinates) {
            return grid[coordinates.y * columns + coordinates.x];
        }

        auto begin() {return grid.begin();};
        auto end() {return grid.end();};
    
        auto size() {return grid.size();}
    };
}
#endif

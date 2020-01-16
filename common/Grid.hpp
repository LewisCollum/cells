#ifndef GRID
#define GRID

#include <array>
#include <ostream>
#include <string>
#include <iterator>

template<typename Element, size_t columns, size_t rows>
struct Grid {
    using value_type = Element;
    
private:
    std::array<value_type, columns*rows> grid;
    
public:
    bool isWithinBounds(size_t x, size_t y) {
        return x < columns and x >= 0 and y < rows and y >= 0;
    }

    Element & at(size_t x, size_t y) {
        return grid[y * columns + x];
    }

    auto begin() {return grid.begin();};
    auto end() {return grid.end();};
    
    auto size() {return grid.size();}
};

#endif

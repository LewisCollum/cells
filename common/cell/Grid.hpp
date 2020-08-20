#ifndef CELLGRID
#define CELLGRID

#include <functional>
#include "rectangle/Grid.hpp"
#include "cell/Cell.hpp"

namespace cell {
    template <size_t columns, size_t rows>
    struct Grid : rectangle::Grid<Cell, columns, rows> {
        size_t unvisited;
    
        Grid() : unvisited{columns*rows-1} {
            for (size_t x = 0; x < columns; ++x) {
                for (size_t y = 0; y < rows; ++y) {
                    auto & cell = this->at(x, y);

                    if (this->isWithinBounds(x+1, y))
                        cell.east = this->at(x+1, y);
                
                    if (this->isWithinBounds(x-1, y))
                        cell.west = this->at(x-1, y);
                
                    if (this->isWithinBounds(x, y+1))
                        cell.south = this->at(x, y+1);                    

                    if (this->isWithinBounds(x, y-1))
                        cell.north = this->at(x, y-1);
                }
            }
        }
        
        void carveWithStrategy(std::function<void(cell::Grid<columns, rows>&)> const & carvingStrategy) {
            carvingStrategy(*this);
        }
    };
}

#endif

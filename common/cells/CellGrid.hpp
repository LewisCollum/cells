#ifndef CELLGRID
#define CELLGRID

#include <functional>
#include "Grid.hpp"
#include "Cell.hpp"

template <size_t columns, size_t rows>
struct CellGrid : Grid<Cell, columns, rows> {
    size_t unvisited;
    
    CellGrid() : unvisited{columns*rows-1} {
        for (size_t x = 0; x < columns; ++x) {
            for (size_t y = 0; y < rows; ++y) {
                auto & [neighbors, linker] = this->at(x, y);

                if (this->isWithinBounds(x+1, y))
                    neighbors.setEast(this->at(x+1, y));
                
                if (this->isWithinBounds(x-1, y))
                    neighbors.setWest(this->at(x-1, y));
                
                if (this->isWithinBounds(x, y+1))
                    neighbors.setSouth(this->at(x, y+1));                    

                if (this->isWithinBounds(x, y-1))
                    neighbors.setNorth(this->at(x, y-1));                 
            }
        }
    }
        
    void carveWithStrategy(const std::function<void(CellGrid<columns, rows>&)>& carvingStrategy) {
        carvingStrategy(*this);
    }
};

#endif

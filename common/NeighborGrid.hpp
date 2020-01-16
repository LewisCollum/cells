#ifndef NEIGHBORGRID
#define NEIGHBORGRID

#include "Grid.hpp"
#include "Neighbors.hpp"

namespace NeighborGrid {
    template<typename NeighborType, size_t columns, size_t rows>
    using Type = Grid<Neighbors<NeighborType>, columns, rows>;
    
    template<typename NeighborType, size_t columns, size_t rows>
    Type<NeighborType, columns, rows> fromGrid(Grid<NeighborType, columns, rows> & grid) {
        Type<NeighborType, columns, rows> neighborGrid;
        
        for (size_t x = 0; x < columns; ++x) {
            for (size_t y = 0; y < rows; ++y) {
                Neighbors<NeighborType> & currentNeighbors = neighborGrid.at(x, y);

                currentNeighbors.setHere(grid.at(x, y));
                
                if (neighborGrid.isWithinBounds(x+1, y))
                    currentNeighbors.setEast(neighborGrid.at(x+1, y));

                if (neighborGrid.isWithinBounds(x-1, y))
                    currentNeighbors.setWest(neighborGrid.at(x-1, y));

                if (neighborGrid.isWithinBounds(x, y+1))
                    currentNeighbors.setSouth(neighborGrid.at(x, y+1));                    

                if (neighborGrid.isWithinBounds(x, y-1))
                    currentNeighbors.setNorth(neighborGrid.at(x, y-1)); 
            }
        }
        return neighborGrid;
    }
};

#endif

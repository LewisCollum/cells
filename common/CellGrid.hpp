#ifndef CELLGRID
#define CELLGRID

#include "Grid.hpp"
#include "Cell.hpp"

namespace CellGrid {
    template<size_t columns, size_t rows>
    using Type = Grid<Cell, columns, rows>;

    template<size_t columns, size_t rows>        
    void setCellNeighbors(Type<columns, rows> & grid) {
        for (size_t x = 0; x < columns; ++x) {
            for (size_t y = 0; y < rows; ++y) {
                Cell & currentCell = grid.at(x, y);
                
                if (grid.isWithinBounds(x+1, y))
                    currentCell.neighbors.setEast(grid.at(x+1, y));

                if (grid.isWithinBounds(x-1, y))
                    currentCell.neighbors.setWest(grid.at(x-1, y));

                if (grid.isWithinBounds(x, y+1))
                    currentCell.neighbors.setSouth(grid.at(x, y+1));                    

                if (grid.isWithinBounds(x, y-1))
                    currentCell.neighbors.setNorth(grid.at(x, y-1)); 
            }
        }
    }
};

#endif

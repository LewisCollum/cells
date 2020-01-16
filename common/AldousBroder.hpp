#ifndef ALDOUSBRODER
#define ALDOUSBRODER

#include "CellGrid.hpp"
#include "RandomSelector.hpp"
#include <iostream>

namespace CellGrid {
    template<size_t columns, size_t rows>
    static void aldousBroder(CellGrid::Type<columns, rows> & grid) {
        auto neighbors = RandomSelector::select(grid.neighborGrid);
        
        while (grid.unvisited > 0) {
            auto * neighbor = RandomSelector::select(neighbors);
            if (!neighbor->getHere()->hasLinks()) {
                neighbors.getHere()->link(*neighbor->getHere());
                --grid.unvisited;
            }

            neighbors = *neighbor;
        }
	}    
};
#endif

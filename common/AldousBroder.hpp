#ifndef ALDOUSBRODER
#define ALDOUSBRODER

#include "CellGrid.hpp"
#include "RandomSelector.hpp"

template<size_t columns, size_t rows>
static void aldousBroder(CellGrid<columns, rows> & grid) {
    size_t unvisited = columns*rows-1;
    auto * cell = RandomSelector::select(grid.begin(), grid.end());
    
    while (unvisited > 0) {
        auto * choice = RandomSelector::select(cell->neighbors);
        
        if (!choice->linker.hasLinks()) {
            cell->linker.link(choice->linker);
            --unvisited;
            }
        
        cell = choice;
    }
}

#endif

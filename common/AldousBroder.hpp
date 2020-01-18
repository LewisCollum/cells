#ifndef ALDOUSBRODER
#define ALDOUSBRODER

#include "CellGrid.hpp"
#include "RandomSelector.hpp"

template<size_t columns, size_t rows>
static void aldousBroder(CellGrid<columns, rows> & grid) {
    Cell * cell = RandomSelector::select(grid.begin(), grid.end());
    while (cell->linker.hasLinks()) cell = RandomSelector::select(grid.begin(), grid.end());

    while (grid.unvisited > 0) {
        Cell * choice = RandomSelector::select(cell->neighbors);

        if (!choice->linker.hasLinks()) {
            cell->linker.link(choice->linker);
            --grid.unvisited;
        }
        
        cell = choice;
    }
}

#endif

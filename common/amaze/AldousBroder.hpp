#ifndef ALDOUSBRODER
#define ALDOUSBRODER

#include "cell/Cell.hpp"
#include "cell/Grid.hpp"
#include "RandomSelector.hpp"

namespace AldousBroder {
    template<size_t columns, size_t rows>
    void link(cell::Grid<columns, rows> & grid) {
        cell::Cell * cell = RandomSelector::select(grid.begin(), grid.end());
        while (cell->hasLinks())
            cell = RandomSelector::select(grid.begin(), grid.end());

        while (grid.unvisited > 0) {
            auto * choice = RandomSelector::select(cell->neighbors);

            if (!choice->hasLinks()) {
                cell->link(*choice);
                --grid.unvisited;
            }
        
            cell = choice;
        }
    }
}
#endif

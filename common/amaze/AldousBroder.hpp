#ifndef ALDOUSBRODER
#define ALDOUSBRODER

#include "cell/Cell.hpp"
#include "cell/Neighbors.hpp"
#include "cell/Grid.hpp"
#include "RandomSelector.hpp"

namespace AldousBroder {
    cell::Cell * neighborSelector(cell::Neighbors<cell::Cell> & neighbors) {
        return RandomSelector::select(neighbors);
    }

    template<size_t columns, size_t rows>
    void link(cell::Grid<columns, rows> & grid) {
        cell::Cell * cell = RandomSelector::select(grid.begin(), grid.end());
        while (cell->hasLinks())
            cell = RandomSelector::select(grid.begin(), grid.end());

        while (grid.unvisited > 0) {
            cell::Cell * choice = cell->selectNeighbor(neighborSelector);

            if (!choice->hasLinks()) {
                cell->link(*choice);
                --grid.unvisited;
            }
        
            cell = choice;
        }
    }
}
#endif

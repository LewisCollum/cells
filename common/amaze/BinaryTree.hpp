#ifndef BINARYTREE
#define BINARYTREE

#include "cell/Cell.hpp"
#include "cell/Neighbors.hpp"
#include "cell/Grid.hpp"
#include "RandomSelector.hpp"

namespace BinaryTree {
    cell::Cell * neighborSelector(cell::Neighbors<cell::Cell> & neighbors) {
        return RandomSelector::select({neighbors.getEast(), neighbors.getNorth()});
    }    
    
    template<size_t columns, size_t rows>
    void link(cell::Grid<columns, rows> & grid) {
        for (auto & cell : grid) {
            auto * choice = cell.selectNeighbor(neighborSelector);
            if (choice != nullptr)
                cell.link(*choice);
        }
    }
}


#endif

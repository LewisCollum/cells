#ifndef BINARYTREE
#define BINARYTREE

#include "CellGrid.hpp"
#include "RandomSelector.hpp"

template<size_t columns, size_t rows>
void binaryTree(CellGrid<columns, rows> & grid) {
    for (auto & [neighbors, linker] : grid) {
        auto * choice = RandomSelector::select({neighbors.getEast(), neighbors.getNorth()});
        if (choice != nullptr)
            linker.link(choice->linker);
    }
}


#endif

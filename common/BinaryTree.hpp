#ifndef BINARYTREE
#define BINARYTREE

#include "CellGrid.hpp"
#include "RandomSelector.hpp"

namespace CellGrid {
    template<size_t columns, size_t rows>
    void binaryTree(CellGrid::Type<columns, rows> & grid) {
        grid.forEachCell([](auto & neighbors, auto & linker) {
            auto * choice = RandomSelector::select({neighbors.getEast(), neighbors.getNorth()});
            if (choice != nullptr)
                linker.link(*choice->getHere());
        });
	}
};

#endif

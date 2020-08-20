#ifndef BINARYTREE
#define BINARYTREE

#include "cell/Cell.hpp"
#include "cell/Grid.hpp"
#include "RandomSelector.hpp"

namespace BinaryTree {
    template<size_t columns, size_t rows>
    void link(cell::Grid<columns, rows> & grid) {
        for (auto & cell : grid) {
            auto * choice = RandomSelector::select({cell.east.get(), cell.north.get()});
            if (choice != nullptr)
                cell.link(*choice);
        }
    }
}


#endif

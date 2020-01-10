#ifndef CELL
#define CELL

#include <forward_list>
#include <algorithm>
#include "Linker.hpp"
#include "Neighbors.hpp"

struct Cell {
    Neighbors<Cell> neighbors{};
    BidirectionalLinker linker{};
};

#endif

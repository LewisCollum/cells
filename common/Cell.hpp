#ifndef CELL
#define CELL

#include "Linker.hpp"
#include "Neighbors.hpp"

struct Cell {
    Neighbors<Cell> neighbors{};
    BidirectionalLinker linker{};
};

#endif

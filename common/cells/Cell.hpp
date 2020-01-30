#ifndef CELL
#define CELL

#include "Neighbors.hpp"
#include "Linker.hpp"

struct Cell {
    Neighbors<Cell> neighbors;
    BidirectionalLinker linker;
};

#endif

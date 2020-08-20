#ifndef CELL
#define CELL

#include "cell/Neighbor.hpp"
#include "cell/Linker.hpp"

namespace cell {
    struct Cell;
    using Neighbors = Neighbor<Cell>::Group;
    
    struct Cell {
        Neighbors neighbors;
        BidirectionalLinker linker;

        Neighbor<Cell> west{neighbors};
        Neighbor<Cell> east{neighbors};
        Neighbor<Cell> south{neighbors};
        Neighbor<Cell> north{neighbors}; 

        void link(Cell & cell) {
            linker.link(cell.linker);
        }

        void link(Neighbor<Cell> & neighbor) {
            linker.link(neighbor->linker);
        }

        bool isLinkedTo(Cell const & other) const {
            return linker.isLinkedTo(other.linker);
        }

        bool isLinkedTo(Neighbor<Cell> const & neighbor) const {
            return linker.isLinkedTo(neighbor->linker);
        }

        bool hasLinks() {
            return linker.hasLinks();
        }
    };
}
#endif

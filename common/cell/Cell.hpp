#ifndef CELL
#define CELL

#include "cell/Neighbors.hpp"
#include "cell/Linker.hpp"
namespace cell {
    struct Cell {
        cell::Neighbors<Cell> neighbors;
        cell::BidirectionalLinker linker;

        void setEast(Cell & east) {neighbors.setEast(east);}
        void setWest(Cell & west) {neighbors.setWest(west);}
        void setNorth(Cell & north) {neighbors.setNorth(north);}
        void setSouth(Cell & south) {neighbors.setSouth(south);}    

        void link(Cell & cell) {
            linker.link(cell.linker);
        }

        bool hasLinks() {
            return linker.hasLinks();
        }

        Cell * selectNeighbor(auto & selector) {
            return selector(neighbors);
        }
    
        bool isEastLinkedToSouthEast() {
            Cell * southEast = neighbors.getEast()->neighbors.getSouth();
            return neighbors.getEast()->linker.isLinkedTo(southEast->linker);
        }

        bool isSouthLinkedToSouthEast() {
            Cell * southEast = neighbors.getSouth()->neighbors.getEast();
            return neighbors.getSouth()->linker.isLinkedTo(southEast->linker);
        }
    
        bool isLinkedToEast() {
            return linker.isLinkedTo(neighbors.getEast()->linker);
        }

        bool isLinkedToSouth() {
            return linker.isLinkedTo(neighbors.getSouth()->linker);
        }    
    };
}
#endif

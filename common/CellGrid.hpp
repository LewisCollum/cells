#ifndef CELLGRID
#define CELLGRID

#include <utility>
#include <functional>
#include "Grid.hpp"
#include "NeighborGrid.hpp"
#include "Linker.hpp"

namespace CellGrid {
    // template <size_t columns, size_t rows>
    // using Cell = std::tuple<NeighborGrid::Type<BidirectionalLinker, columns, rows>, Grid<BidirectionalLinker, columns, rows>>;
    
    template <size_t columns, size_t rows>
    struct Type {
        NeighborGrid::Type<BidirectionalLinker, columns, rows> & neighborGrid;
        Grid<BidirectionalLinker, columns, rows> & linkerGrid;

        size_t unvisited = columns*rows-1;
        
        void forEachCell(const std::function<void(Neighbors<BidirectionalLinker>&, BidirectionalLinker&)>& onCurrentCell) {
            for(size_t x = 0; x < columns; ++x) {
                for (size_t y = 0; y < rows; ++y) {
                    Neighbors<BidirectionalLinker> & currentNeighbors = this->neighborGrid.at(x, y);
                    BidirectionalLinker & currentLinker = this->linkerGrid.at(x, y);
                    onCurrentCell(currentNeighbors, currentLinker);
                }
            }
        }

        void carveWithStrategy(const std::function<void(Type<columns, rows>&)>& carvingStrategy) {
            carvingStrategy(*this);
        }
    };
};


#endif

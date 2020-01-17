#include <iostream>
#include "CellGrid.hpp"
#include "BinaryTree.hpp"
#include "GridConverter.hpp"
#include "AldousBroder.hpp"
#include <iterator>

struct Room {
    std::pair<size_t, size_t> x;
    std::pair<size_t, size_t> y;

    template <size_t columns, size_t rows>
    void cut(CellGrid<columns, rows>& grid) {
        // only perimeter cells
        for (size_t i = x.first; i <= x.second; ++i) {
            for (size_t j = y.first; j <= y.second; j += (i==x.first or i==x.second) ? 1 : y.second-y.first) {
                Cell & cell = grid.at(i, j);
                if (i == x.first and x.first != 0) {
                    cell.neighbors.getWest()->neighbors.unlinkEast();
                    cell.neighbors.unlinkWest();
                } else if (i == x.second and x.second != columns-1) {
                    cell.neighbors.getEast()->neighbors.unlinkWest();
                    cell.neighbors.unlinkEast();
                }

                if (j == y.first and y.first != 0) {
                    cell.neighbors.getNorth()->neighbors.unlinkSouth();
                    cell.neighbors.unlinkNorth();
                } else if (j == y.second and y.second != rows-1) {
                    cell.neighbors.getSouth()->neighbors.unlinkNorth();
                    cell.neighbors.unlinkSouth();
                } 
            }
        }
        grid.unvisited -= (x.second-x.first+1)*(y.second-y.first+1);
    }

    template <size_t columns, size_t rows>
    void fill(CellGrid<columns, rows>& grid) {
        for (size_t i = x.first; i <= x.second; ++i) {
            for (size_t j = y.first + i%2; j <= y.second; j += 2) {
                auto & [neighbors, linker] = grid.at(i, j);
                for (auto * neighbor : neighbors) {
                    linker.link(neighbor->linker);
                }
            }
        }
    }
};

int main() {
    CellGrid<10, 10> aldousGrid;
    Room room{x:{0, 2}, y:{1, 3}};
    room.cut(aldousGrid);
    room.fill(aldousGrid);
    Room room2{x:{0, 2}, y:{5, 8}};
    room2.cut(aldousGrid);
    room2.fill(aldousGrid);    
    aldousBroder<10, 10>(aldousGrid);
	std::cout << GridConverter::gridToString(aldousGrid);

    // CellGrid<10, 10> binaryGrid;
    // binaryGrid.carveWithStrategy(binaryTree<10, 10>);
	// std::cout << GridConverter::gridToString(binaryGrid);
    
	return 0;
}

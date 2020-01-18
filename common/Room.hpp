#ifndef ROOM
#define ROOM

#include "CellGrid.hpp"
#include <iostream>

struct Room {
    std::pair<int, int> xBounds;
    std::pair<int, int> yBounds;

    int width() const {
        return xBounds.second-xBounds.first+1;
    }

    int height() const {
        return yBounds.second-yBounds.first+1;
    }

    bool isWithinBounds(int x, int y) {
        return y >= yBounds.first and
            y <= yBounds.second and
            x <= xBounds.second and
            x >= xBounds.first;
    }

    bool isOverlappingRoom(Room const & room) const {
        int xDistance = room.xBounds.first - xBounds.first;
        bool isXOverlapping = xDistance >= 0 ? width() >= xDistance : room.width() >= abs(xDistance);
        
        int yDistance = room.yBounds.first - yBounds.first;
        bool isYOverlapping = yDistance >= 0 ? height() >= yDistance : room.height() >= abs(yDistance);
        
        return isXOverlapping and isYOverlapping;
    }

    template<typename Container>
    bool isOverlappingRooms(Container rooms) {
        for (auto const & room : rooms)
            if (isOverlappingRoom(room)) return true;
        return false;            
    }
    
    template <size_t columns, size_t rows>
    void cut(CellGrid<columns, rows>& grid) {
        // onlyBounds perimeter cells
        for (size_t i = xBounds.first; i <= xBounds.second; ++i) {
            for (size_t j = yBounds.first; j <= yBounds.second; j += (i==xBounds.first or i==xBounds.second) ? 1 : yBounds.second-yBounds.first) {
                Cell & cell = grid.at(i, j);
                if (i == xBounds.first and xBounds.first != 0) {
                    cell.neighbors.getWest()->neighbors.unlinkEast();
                    cell.neighbors.unlinkWest();
                } else if (i == xBounds.second and xBounds.second != columns-1) {
                    cell.neighbors.getEast()->neighbors.unlinkWest();
                    cell.neighbors.unlinkEast();
                }

                if (j == yBounds.first and yBounds.first != 0) {
                    cell.neighbors.getNorth()->neighbors.unlinkSouth();
                    cell.neighbors.unlinkNorth();
                } else if (j == yBounds.second and yBounds.second != rows-1) {
                    cell.neighbors.getSouth()->neighbors.unlinkNorth();
                    cell.neighbors.unlinkSouth();
                } 
            }
        }
        grid.unvisited -= (xBounds.second-xBounds.first+1)*(yBounds.second-yBounds.first+1);
    }

    template <size_t columns, size_t rows>
    void fill(CellGrid<columns, rows>& grid) {
        for (size_t i = xBounds.first; i <= xBounds.second; ++i) {
            for (size_t j = yBounds.first + i%2; j <= yBounds.second; j += 2) {
                auto & [neighbors, linker] = grid.at(i, j);
                for (auto * neighbor : neighbors) {
                    linker.link(neighbor->linker);
                }
            }
        }
    }
};

#endif

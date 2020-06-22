#ifndef ROOM
#define ROOM

#include "cell/Grid.hpp"
#include "rectangle/Limits.hpp"
#include "rectangle/Boundary.hpp"

class Room {
    rectangle::Limits limits;
    rectangle::Boundary boundary;

public:
    Room(rectangle::Limits const & limits) : limits{limits}, boundary{limits} {}
    
    bool isWithinBounds(int x, int y) const {
        return y >= limits.y.first and
            y <= limits.y.second and
            x <= limits.x.second and
            x >= limits.x.first;
    }

    bool isOverlappingRoom(Room const & room) const {
        int xDistance = room.limits.x.first - limits.x.first;
        bool isXOverlapping = xDistance >= 0 ? limits.width() >= xDistance : room.limits.width() >= abs(xDistance);
        
        int yDistance = room.limits.y.first - limits.y.first;
        bool isYOverlapping = yDistance >= 0 ? limits.height() >= yDistance : room.limits.height() >= abs(yDistance);
        
        return isXOverlapping and isYOverlapping;
    }

    template<typename Container>
    bool isOverlappingRooms(Container const & rooms) const {
        for (auto const & room : rooms)
            if (isOverlappingRoom(room)) return true;
        return false;            
    }
    
    template <size_t columns, size_t rows>
    void cut(cell::Grid<columns, rows>& grid) {
        // only perimeter cells
        for (int i = limits.x.first; i <= limits.x.second; ++i) {
            for (int j = limits.y.first; j <= limits.y.second; j += (i==limits.x.first or i==limits.x.second) ? 1 : limits.y.second-limits.y.first) {
                auto & cell = grid.at(i, j);
                if (i == limits.x.first and limits.x.first != 0) {
                    cell.neighbors.getWest()->neighbors.unlinkEast();
                    cell.neighbors.unlinkWest();
                } else if (i == limits.x.second and limits.x.second != columns-1) {
                    cell.neighbors.getEast()->neighbors.unlinkWest();
                    cell.neighbors.unlinkEast();
                }

                if (j == limits.y.first and limits.y.first != 0) {
                    cell.neighbors.getNorth()->neighbors.unlinkSouth();
                    cell.neighbors.unlinkNorth();
                } else if (j == limits.y.second and limits.y.second != rows-1) {
                    cell.neighbors.getSouth()->neighbors.unlinkNorth();
                    cell.neighbors.unlinkSouth();
                } 
            }
        }
    }

    template <size_t columns, size_t rows>
    void fill(cell::Grid<columns, rows>& grid) {
        for (int i = limits.x.first; i <= limits.x.second; ++i) {
            for (int j = limits.y.first; j <= limits.y.second; ++j) {
                auto & [neighbors, linker] = grid.at(i, j);
                if (neighbors.getNorth() != nullptr and j > limits.y.first)
                    linker.link(neighbors.getNorth()->linker);
                if (neighbors.getEast() != nullptr and i < limits.x.second)
                    linker.link(neighbors.getEast()->linker);
            }
        }
        grid.unvisited -= limits.width()*limits.height();
    }
};

#endif

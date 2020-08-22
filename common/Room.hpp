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
        boundary.forEachLateralCoordinates([&](auto & coordinatePair){
            if (grid.isWithinBounds(coordinatePair.first) and grid.isWithinBounds(coordinatePair.second)) {
                cell::Cell & first = grid.at(coordinatePair.first);
                cell::Cell & second = grid.at(coordinatePair.second);
                first.clearNeighbor(second);
                second.clearNeighbor(first);
            }
        });
    }

    template <size_t columns, size_t rows>
    void fill(cell::Grid<columns, rows>& grid) {
        for (int i = limits.x.first; i <= limits.x.second; ++i) {
            for (int j = limits.y.first; j <= limits.y.second; ++j) {
                cell::Cell & cell = grid.at(i, j);
                if (cell.north.get() != nullptr and j > limits.y.first)
                    cell.link(cell.north);
                if (cell.east.get() != nullptr and i < limits.x.second)
                    cell.link(cell.east);
            }
        }
        grid.unvisited -= limits.width()*limits.height();
    }
};

#endif

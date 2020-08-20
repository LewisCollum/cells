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
        bool isTouchingLeftBorder = limits.x.first == 0;
        bool isTouchingRightBorder = limits.x.second == columns - 1;     
        bool isTouchingTopBorder = limits.y.first == 0;
        bool isTouchingBottomBorder = limits.y.second == rows - 1;

        // only perimeter cells
        for (int i = limits.x.first; i <= limits.x.second; ++i) {
            bool isFirstColumnToCut = i == limits.x.first;
            bool isLastColumnToCut = i == limits.x.second;

            int rowIncrement = (isFirstColumnToCut or isLastColumnToCut) ?
                1 : limits.y.second-limits.y.first;
            
            for (int j = limits.y.first; j <= limits.y.second; j += rowIncrement) {
                auto & cell = grid.at(i, j);
                
                if (isFirstColumnToCut and not isTouchingLeftBorder) {
                    cell.west->east.clear();
                    cell.west.clear();
                } else if (isLastColumnToCut and not isTouchingRightBorder) {
                    cell.east->west.clear();
                    cell.east.clear();
                }

                bool isFirstRowToCut = j == limits.y.first;
                bool isLastRowToCut = j == limits.y.second;
                if (isFirstRowToCut and not isTouchingTopBorder) {
                    cell.north->south.clear();
                    cell.north.clear();
                } else if (isLastRowToCut and not isTouchingBottomBorder) {
                    cell.south->north.clear();
                    cell.south.clear();
                } 
            }
        }
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

#ifndef ROOMS
#define ROOMS

#include <iostream>
#include <vector>
#include "Room.hpp"
#include "RandomSelector.hpp"

namespace Rooms{
    using container_type = std::vector<Room>;
    
    container_type generateWithinArea(size_t width, size_t height, int numberOfAttempts) {
        container_type rooms;
        for (; numberOfAttempts != 0; --numberOfAttempts) {
            int roomWidth = RandomSelector::select(2, 5);
            int roomHeight = RandomSelector::select(2, 5);
            int xRandom = RandomSelector::select(0, width-roomWidth);
            int yRandom = RandomSelector::select(0, height-roomHeight);

            Room roomCandidate = Room{
              xBounds: {xRandom,xRandom+roomWidth-1},
              yBounds: {yRandom,yRandom+roomHeight-1}};

            if (!roomCandidate.isOverlappingRooms(rooms))
                rooms.emplace_back(roomCandidate);
        }
        return rooms;
    }
};

#endif

#ifndef ROOMS
#define ROOMS

#include <vector>
#include <memory>

#include "Room.hpp"
#include "RandomSelector.hpp"
#include "rectangle/Limits.hpp"

namespace Rooms{
    using container_type = std::vector<Room>;
    
    container_type generateWithinArea(size_t width, size_t height, int numberOfAttempts) {
        container_type rooms;
        for (; numberOfAttempts != 0; --numberOfAttempts) {
            int roomWidth = RandomSelector::select(2, 5);
            int roomHeight = RandomSelector::select(2, 5);
            int xRandom = RandomSelector::select(0, width-roomWidth);
            int yRandom = RandomSelector::select(0, height-roomHeight);

            rectangle::Limits limits = {
              x: {xRandom, xRandom+roomWidth-1},
              y: {yRandom, yRandom+roomHeight-1}};
            Room roomCandidate(limits);

            if (!roomCandidate.isOverlappingRooms(rooms))
                rooms.emplace_back(roomCandidate);
        }
        return rooms;
    }
}

#endif

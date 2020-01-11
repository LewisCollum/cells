#ifndef NEIGHBORS
#define NEIGHBORS

#include <unordered_map>

template<typename NeighborType>
struct Neighbors {

    enum class Direction {NORTH, SOUTH, EAST, WEST};

    std::unordered_map<Direction, NeighborType *> all;

    void setEast(NeighborType & value) { setDirection(Direction::EAST, value); }
    void setWest(NeighborType & value) { setDirection(Direction::WEST, value); }
    void setNorth(NeighborType & value) { setDirection(Direction::NORTH, value); }
    void setSouth(NeighborType & value) { setDirection(Direction::SOUTH, value); }
    
    NeighborType * getEast() { return getDirection(Direction::EAST); }
    NeighborType * getWest() { return getDirection(Direction::WEST); }
    NeighborType * getNorth() { return getDirection(Direction::NORTH); }
    NeighborType * getSouth() { return getDirection(Direction::SOUTH); }

    void detach(NeighborType & neighbor) {
        auto detachable = std::find_if(all.begin(), all.end(), [&](auto pair) {
            return pair.second == &neighbor;
        });

        if (detachable != all.end())
            all.erase(detachable);
    }

private:
    void setDirection(Direction direction, NeighborType & value) {
        // Ensure that 'all' doesn't increase in size due to a nullptr being emplaced
        all.emplace(direction, &value);
    }

    NeighborType * getDirection(Direction direction) {
        // Nullptr indicates that a neighbor does not exist.
        return all.contains(direction)?
            all[direction]:
            nullptr;
    }
};

#endif

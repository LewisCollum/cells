#ifndef NEIGHBORS
#define NEIGHBORS

#include <unordered_map>
#include <forward_list>
#include <utility>

template<typename NeighborType>
struct Neighbors {
    enum class Direction {NORTH, SOUTH, EAST, WEST};
    using key_type = Direction;
    using mapped_type = NeighborType*;
    
    std::unordered_map<key_type, mapped_type> all;
    
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

    auto begin() { return all.begin(); }
    auto end() { return all.end(); }
    auto operator[](auto key){ all[key]; };
    
private:
    void setDirection(Direction direction, NeighborType & value) {
        all.emplace(direction, &value);
    }

    NeighborType * getDirection(Direction direction) {
        return all.contains(direction)?
            all[direction]:
            nullptr;
    }
};

#endif

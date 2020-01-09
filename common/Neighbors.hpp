#ifndef NEIGHBORS
#define NEIGHBORS

#include <array>

template<typename NeighborType>
struct Neighbors {
    
    std::array<NeighborType*, 4> all;

    enum Direction {NORTH, SOUTH, EAST, WEST};

    void setEast(NeighborType* value) { all[Direction::EAST] = value; }
    void setWest(NeighborType* value) { all[Direction::WEST] = value; }
    void setNorth(NeighborType* value) { all[Direction::NORTH] = value; }
    void setSouth(NeighborType* value) { all[Direction::SOUTH] = value; }
    
    NeighborType const* getEast() const { return all[Direction::EAST]; }
    NeighborType const* getWest() const { return all[Direction::WEST]; }
    NeighborType const* getNorth() const { return all[Direction::NORTH]; }
    NeighborType const* getSouth() const { return all[Direction::SOUTH]; }
};

#endif

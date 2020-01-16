#ifndef NEIGHBORS
#define NEIGHBORS

#include <unordered_set>
#include <utility>

template<typename NeighborType>
struct Neighbors {
    using value_type = NeighborType;
    using value_pointer = value_type*;
    using value_reference = value_type&;
    using reference = Neighbors<value_type>&;
    using pointer = Neighbors<value_type>*;
    
private:    
    std::unordered_set<pointer> neighbors;
    pointer east, west, north, south;
    value_pointer here;
    
public:
    Neighbors() : east{nullptr}, west{nullptr}, north{nullptr}, south{nullptr} {}
    
    void setEast(reference value) { setDirection(east, value); }
    void setWest(reference value) { setDirection(west, value); }
    void setNorth(reference value) { setDirection(north, value); }
    void setSouth(reference value) { setDirection(south, value); }

    void setHere(value_reference value) { here = &value; }
    value_pointer const getHere() { return here; }

    void unlinkEast() { unlink(east); }
    void unlinkWest() { unlink(west); }
    void unlinkNorth() { unlink(north); }
    void unlinkSouth() { unlink(south); }
    
    pointer const getEast() { return east; }
    pointer const getWest() { return west; }
    pointer const getNorth() { return north; }
    pointer const getSouth() { return south; }
    
    auto begin() { return neighbors.begin(); }
    auto end() { return neighbors.end(); }
    
private:    
    void setDirection(pointer & direction, reference value) {
        if (direction == nullptr) {
            direction = &value;
            neighbors.emplace(direction);
        }
    }

    void unlink(pointer & direction) {
        if (direction != nullptr) {
            neighbors.erase(direction);
            direction = nullptr;
        }
    }
    
};

#endif

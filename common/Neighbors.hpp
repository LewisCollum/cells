#ifndef NEIGHBORS
#define NEIGHBORS

#include <unordered_set>

template<typename NeighborType>
struct Neighbors {
    using value_type = NeighborType;
    using value_pointer = value_type*;
    using value_reference = value_type&;
    
private:    
    std::unordered_set<value_pointer> neighbors;
    value_pointer east, west, north, south;
    
public:
    Neighbors() : east{nullptr}, west{nullptr}, north{nullptr}, south{nullptr} {}
    
    void setEast(value_reference value) { setDirection(east, value); }
    void setWest(value_reference value) { setDirection(west, value); }
    void setNorth(value_reference value) { setDirection(north, value); }
    void setSouth(value_reference value) { setDirection(south, value); }

    void unlinkEast() { unlink(east); }
    void unlinkWest() { unlink(west); }
    void unlinkNorth() { unlink(north); }
    void unlinkSouth() { unlink(south); }
    
    value_pointer const getEast() { return east; }
    value_pointer const getWest() { return west; }
    value_pointer const getNorth() { return north; }
    value_pointer const getSouth() { return south; }

    auto size() { return neighbors.size(); }
    auto begin() { return neighbors.begin(); }
    auto end() { return neighbors.end(); }
    
private:    
    void setDirection(value_pointer & direction, value_reference value) {
        if (direction == nullptr) {
            direction = &value;
            neighbors.emplace(direction);
        }
    }

    void unlink(value_pointer & direction) {
        if (direction != nullptr) {
            neighbors.erase(direction);
            direction = nullptr;
        }
    }
    
};

#endif

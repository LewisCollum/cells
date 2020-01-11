#ifndef NEIGHBORSELECTOR
#define NEIGHBORSELECTOR

#include "RandomSelector.hpp"
#include "Neighbors.hpp"
#include <forward_list>
#include <initializer_list>

namespace NeighborSelector {
    template<typename NeighborType>
    NeighborType * select(Neighbors<NeighborType> const & neighbors) {
        return neighbors.all.empty() ?
            nullptr :
            RandomSelector::select(neighbors.all).second;
    }

    template<typename NeighborType>
    NeighborType * select(std::initializer_list<NeighborType *> neighbors) {
        std::forward_list<NeighborType *> validNeighbors{};
        for (auto neighbor: neighbors) {
            if (neighbor != nullptr)
                validNeighbors.emplace_front(neighbor);
        }
        
        return validNeighbors.empty() ?
            nullptr :
            RandomSelector::select(validNeighbors);
    }
};

#endif

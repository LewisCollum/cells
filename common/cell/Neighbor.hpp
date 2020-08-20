#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include <unordered_set>

namespace cell {
    template<typename NeighborType>
    class Neighbor {
    public:
        using Group = std::unordered_set<NeighborType*>;
        
    private:
        Group & parent;
        NeighborType * content;
        
    public:
        Neighbor(Group & parent)
            : parent{parent}, content{nullptr}
        {}

        void operator=(NeighborType & value) {
            if (content == nullptr) {
                content = &value;
                parent.emplace(content);
            }
        }

        NeighborType * operator->() const {
            return content;
        }

        NeighborType * get() const {
            return content;
        }

        void clear()
        {
            parent.erase(content);        
            content = nullptr;
        }
    };
}
#endif

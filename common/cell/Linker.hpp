#ifndef LINKER
#define LINKER

#include <forward_list>
#include <algorithm>
#include <utility>

namespace cell {
    template<bool isBidirectional>
    class Linker {
        std::forward_list<Linker*> links;

    public:
        template<bool bidirectional = isBidirectional, std::enable_if_t<bidirectional, int> = 0>
        void link(Linker & other) {
            if (!isLinkedTo(other)) {
                links.emplace_front(&other);
                other.link(*this);
            }
        }
    
        template<bool bidirectional = isBidirectional, std::enable_if_t<bidirectional, int> = 0>
        void unlink(Linker & other) {
            if (isLinkedTo(other)) {
                links.remove(&other);
                other.unlink(*this);
            }
        }
    
        template<bool bidirectional = isBidirectional, std::enable_if_t<not bidirectional, int> = 0>
        void link(Linker & other) {
            if (!isLinkedTo(other))
                links.emplace_front(&other);
        }

        template<bool bidirectional = isBidirectional, std::enable_if_t<not bidirectional, int> = 0> 
        void unlink(Linker & other) {
            if (isLinkedTo(other))
                links.remove(&other);
        }

        bool isLinkedTo(Linker const & other) const {
            return std::find(links.begin(), links.end(), &other) != links.end();
        }

        bool hasLinks() const {
            return !links.empty();
        }

        auto begin() { return links.begin(); }
        auto end() { return links.end(); }
    };

    using BidirectionalLinker = Linker<true>;
    using ForwardLinker = Linker<false>;
}
#endif

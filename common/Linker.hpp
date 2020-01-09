#ifndef LINKER
#define LINKER

#include <forward_list>
#include <algorithm>

template<bool isBidirectional>
class Linker {
	std::forward_list<Linker*> links{};

public:
    void link(Linker& other) {
        if (!isLinkedTo(other)) {
            links.emplace_front(&other);
            if (isBidirectional) other.link(*this);
        }
    }

    void unlink(Linker& other) {
        if (isLinkedTo(other)) {
            links.remove(&other);
            if (isBidirectional) other.unlink(*this);
        }
    }

    bool isLinkedTo(Linker const& other) const {
        return std::find(links.begin(), links.end(), &other) != links.end();
    }

    bool hasLinks() const {
        return !links.empty();
    }
};

using BidirectionalLinker = Linker<true>;
using ForwardLinker = Linker<false>;

#endif

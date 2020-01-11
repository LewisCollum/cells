#ifndef RANDOMSELECTOR
#define RANDOMSELECTOR

#include <random>
#include <iterator>

namespace RandomSelector {
    auto generator = std::default_random_engine(std::random_device()());

	template <typename Iter>
	Iter select(Iter start, Iter end) {
        std::uniform_int_distribution<> distribution(0, std::distance(start, end) - 1);
        std::advance(start, distribution(generator));
        return start;
	}

	template <typename Container>
	auto select(Container & c) -> decltype(*c.begin()) {
		return *select(c.begin(), c.end());
	}    
};

#endif

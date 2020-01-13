#ifndef RANDOMSELECTOR
#define RANDOMSELECTOR

#include <random>
#include <iterator>
#include <utility>
#include <type_traits>
#include "MapType.hpp"
#include <forward_list>

namespace RandomSelector {
    auto generator = std::default_random_engine(std::random_device()());    

	template <typename Iter>
	Iter select(Iter start, Iter end) {
        std::uniform_int_distribution<> distribution(0, std::distance(start, end) - 1);
        std::advance(start, distribution(generator));
        return start;
	}

    // NonMap
    template <typename Container>
	auto select(Container & c, std::false_type, std::false_type) {
		return *select(c.begin(), c.end());
	}

	template <typename Container>
    auto * select(Container & c, std::false_type, std::true_type) {
		return c.begin() != c.end() ?
            *select(c.begin(), c.end()) :
            nullptr;
	}
    
    template<typename Container>
    auto select(Container & c, std::false_type) {
        return select(c, typename std::false_type{}, typename std::is_pointer<typename Container::value_type>::type{});
    }

    
    // Map
    template <typename Container>
    auto select(Container & c, std::true_type, std::false_type) {
        return select(c.begin(), c.end())->second;
	}
    
	template <typename Container>
    auto * select(Container & c, std::true_type, std::true_type) {
        return c.begin() != c.end() ?
            select(c.begin(), c.end())->second :
            nullptr;
	}
    
    template<typename Container>
    auto select(Container & c, std::true_type) {
        return select(c, typename std::true_type{}, typename std::is_pointer<typename Container::mapped_type>::type{});
    }

    // Tag Dispatch 
    template<typename Container>
    auto select(Container & c) {
        return select(c, MapType::isMapType<Container>{});
    }

    // Initializer List
    template<typename T>
    auto * select(std::initializer_list<T*> list) {
        std::forward_list<T*> valids;
        for (auto element: list) {
            if (element != nullptr)
                valids.emplace_front(element);
        }
        
        return RandomSelector::select(valids);
    }    
    
}



#endif

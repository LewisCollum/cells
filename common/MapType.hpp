#include <type_traits>

namespace MapType {
    namespace detail {
        template<typename T>
        using MapType = std::void_t<decltype(std::declval<T&>()[std::declval<const typename T::key_type&>()])>;

        template<typename T, typename U = void>
        struct isMapType : std::false_type { };
    
        template<typename T>
        struct isMapType<T, MapType<T>> : std::true_type { };
    };   

    template<typename T>
    struct isMapType : detail::isMapType<T>::type {};    
}

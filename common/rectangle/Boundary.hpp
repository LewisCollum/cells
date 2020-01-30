#ifndef RECTANGLE_BOUNDARY
#define RECTANGLE_BOUNDARY

#include <functional>
#include <variant>
#include "Limits.hpp"
#include "BoundaryLine.hpp"

namespace rectangle {
    template <rectangle::Limits limits>
    struct Boundary {
        using BoundaryLineTypes = std::variant<
            VerticalBoundaryLine<limits.height()>,
            HorizontalBoundaryLine<limits.width()>>;
        
    private:
        std::array<BoundaryLineTypes, 4> boundaryLines;

    public:    
        static constexpr Coordinates westOrigin{x:limits.x.first-1, y:limits.y.first};
        static constexpr Coordinates eastOrigin{x:limits.x.second-1, y:limits.y.first};
        static constexpr Coordinates southOrigin{x:limits.x.first, y:limits.y.second-1};
        static constexpr Coordinates northOrigin{x:limits.x.first, y:limits.y.first-1};
    
        constexpr Boundary() : boundaryLines {
            VerticalBoundaryLine<limits.height()>{westOrigin},
            VerticalBoundaryLine<limits.height()>{eastOrigin},
            HorizontalBoundaryLine<limits.width()>{southOrigin},
            HorizontalBoundaryLine<limits.width()>{northOrigin}} {};

        using onLateralCoordinates = std::function<void(LateralCoordinates)>;
        constexpr void forEachLateralCoordinates(onLateralCoordinates on) const {
            for (auto const & boundaryLine : boundaryLines)
                std::visit([&](auto visitedBoundaryLine){
                    for (auto const & lateralCoordinates: visitedBoundaryLine)
                        on(lateralCoordinates);
                }, boundaryLine);
        }
    };
}
#endif
